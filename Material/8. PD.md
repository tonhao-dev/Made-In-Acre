# Programação dinâmica

### Problema do Troco
Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum, the task is to find the number of ways to make sum by using different denominations.

#### Bottom-Up
Time complexity : O(N*sum)

Auxiliary Space : O(sum)

```cpp
int count(int coins[], int n, int sum)
{
    // table[i] will be storing the number of solutions for
    // value i. We need sum+1 rows as the dp is
    // constructed in bottom up manner using the base case
    // (sum = 0)
    int dp[sum + 1];

    // Initialize all table values as 0
    memset(dp, 0, sizeof(dp));

    // Base case (If given value is 0)
    dp[0] = 1;

    // Pick all coins one by one and update the table[]
    // values after the index greater than or equal to the
    // value of the picked coin
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];
    return dp[sum];
}


int coins[] = { 1, 2, 3 };
int n = sizeof(coins) / sizeof(coins[0]);
int sum = 5;
cout << count(coins, n, sum); // 5
```

### Top-Down
```cpp
int count(vector<int>& coins, int n, int sum,
          vector<vector<int> >& dp)
{
    // Base Case
    if (sum == 0)
        return dp[n][sum] = 1;

    // If number of coins is 0 or sum is less than 0 then
    // there is no way to make the sum.
    if (n == 0 || sum < 0)
        return 0;

    // If the subproblem is previously calculated then
    // simply return the result
    if (dp[n][sum] != -1)
        return dp[n][sum];

    // Two options for the current coin
    return dp[n][sum]
           = count(coins, n, sum - coins[n - 1], dp)
             + count(coins, n - 1, sum, dp);
}

int n, sum;
n = 3, sum = 5;
vector<int> coins = { 1, 2, 3 };
// 2d dp array to store previously calculated
// results
vector<vector<int> > dp(n + 1,
                        vector<int>(sum + 1, -1));
int res = count(coins, n, sum, dp);
cout << res << endl; // 5
```
### Cortando canos

Dada uma relação de comprimentos de cano e seus respectivos valores de venda, determine o maior valor total que possa ser obtido com o corte de um cano de comprimento inicial determinado.

```cpp
ll lucro_maximo(vector<pll>& canos, ll sizeCano) {
    vll memo(1e4 + 10, 0);
    rep(i, sizeCano + 1) {
        foreach (cano, canos) {
            if (i < cano.f) continue;
            memo[i] = max(memo[i], cano.s + memo[i - cano.f]);
        }
    }
    return memo[sizeCano];
}
```

### Problema da Mochila
Suponha dado um conjunto de objetos, cada um com um certo peso e um certo valor. Quais dos objetos devo colocar na minha mochila para que o valor total seja o maior possível? Minha mochila tem capacidade para 15 kg apenas.

#### Bottom-Up
```cpp
// Function to find the maximum profit
int knapSack(int W, int wt[], int val[], int n)
{
    // Making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {

            if (wt[i - 1] <= w)

                // Finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    // Returning the maximum value of knapsack
    return dp[W];
}
int profit[] = { 60, 100, 120 };
int weight[] = { 10, 20, 30 };
int W = 50;
int n = sizeof(profit) / sizeof(profit[0]);
cout << knapSack(W, weight, profit, n);
```

#### Top-Down
```cpp
class Item {
   public:
    int peso;
    ll valor;
};

vector<vector<ll>> memo(100, vector<ll>(100005, -1));

ll valor_maximo(int item_atual, int capacidade_disponivel, vector<Item>& itens) {
    if (capacidade_disponivel < 0) return -LONG_MAX / 2;
    if (capacidade_disponivel == 0 || item_atual == itens.size()) return 0;

    if (memo[item_atual][capacidade_disponivel] != -1) return memo[item_atual][capacidade_disponivel];

    return memo[item_atual][capacidade_disponivel] = max(
               // Caso a capacidade se torne negativa o retorno será -LONG_MAX, dessa forma assumimos que o valor
               // retornado é tão pequeno que será desconsiderado pelo MAX()
               itens[item_atual].valor + valor_maximo(item_atual + 1, capacidade_disponivel - itens[item_atual].peso, itens),
               valor_maximo(item_atual + 1, capacidade_disponivel, itens));
}
cout << valor_maximo(0, capacidade, itens) << "\n";
```

### Com tracking de itens
```cpp
void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // stores the result of Knapsack
    int res = K[n][W];
    cout<< res << endl;

    w = W;
    for (i = n; i > 0 && res > 0; i--) {

        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;
        else {

            // This item is included.
            cout<<" "<<wt[i - 1] ;

            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

int val[] = { 60, 100, 120 };
int wt[] = { 10, 20, 30 };
int W = 50;
int n = sizeof(val) / sizeof(val[0]);

printknapSack(W, wt, val, n);
```

### Com repetição de itens
```cpp
// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n,
                       int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    // Fill dp[] using above recursive formula
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

    return dp[W];
}
int W = 100;
int val[] = {10, 30, 20};
int wt[] = {5, 10, 15};
int n = sizeof(val)/sizeof(val[0]);

cout << unboundedKnapsack(W, n, val, wt); // 300
```

### Com repetição e tracking dos itens
```cpp
class UnboundedKnapsack {
   public:
    vector<ll> knapsack;
    vector<vector<ll>> selectedElements;
    ll maximumCapacity;

    vector<ll> knapsack_unbounded(vector<ll>& pesos, vector<ll>& valores, ll num_itens, ll capacidade) {
        // Stores the maximum value which can be reached with a certain capacity
        knapsack.clear();
        knapsack.resize(capacidade + 1);

        maximumCapacity = capacidade + 1;

        // Stores selected elements with a certain capacity
        selectedElements.resize(capacidade + 1);

        // Initializes maximum value vector with zero
        for (ll i = 0; i < capacidade + 1; i++) {
            knapsack[i] = 0;
        }

        // Computes the maximum value that can be reached for each capacity
        for (ll capacity = 0; capacity < capacidade + 1; capacity++) {
            // Goes through all the elements
            for (ll n = 0; n < num_itens; n++) {
                if (pesos[n] <= capacity) {
                    if (knapsack[capacity] <= knapsack[capacity - pesos[n]] + valores[n]) {
                        knapsack[capacity] = knapsack[capacity - pesos[n]] + valores[n];

                        // Stores selected elements
                        selectedElements[capacity].clear();
                        selectedElements[capacity].push_back(n + 1);

                        for (ll elem : selectedElements[capacity - pesos[n]]) {
                            selectedElements[capacity].push_back(elem);
                        }
                    }
                }
            }
        }

        return this->selectedElements[capacidade];
    }
};

UnboundedKnapsack mochila;
vll index_itens_escolhidos = mochila.knapsack_unbounded(pesos, valores, num_itens, capacidade);

ll sum = 0;
foreach (i, index_itens_escolhidos) {
    sum += valores[i - 1];
}

log(sum);
```

### Problema da mochila fracionado
Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack.

```cpp
struct Item {
    int profit, weight;

    // Constructor
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

// Comparison function to sort Item
// according to profit/weight ratio
static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
    // Sorting Item on basis of ratio
    sort(arr, arr + N, cmp);

    double finalvalue = 0.0;

    // Looping through all items
    for (int i = 0; i < N; i++) {

        // If adding Item won't overflow,
        // add it completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }

        // If we can't add current Item,
        // add fractional part of it
        else {
            finalvalue
                += arr[i].profit
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    // Returning final value
    return finalvalue;
}

int W = 50;
Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
int N = sizeof(arr) / sizeof(arr[0]);

cout << fractionalKnapsack(W, arr, N); // 240
```

### LCS

Given two strings, S1 and S2, the task is to find the length of the Longest Common Subsequence, i.e. longest subsequence present in both of the strings.

A longest common subsequence (LCS) is defined as the longest subsequence which is common in all given input sequences.

### Bottom-Up

Time Complexity: O(m * n) which remains the same.

Auxiliary Space: O(m) because the algorithm uses two arrays of size m.

```cpp
int longestCommonSubsequence(string& text1, string& text2)
{
    int n = text1.size();
    int m = text2.size();

    // initializing 2 vectors of size m
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int idx2 = 0; idx2 < m + 1; idx2++)
        cur[idx2] = 0;

    for (int idx1 = 1; idx1 < n + 1; idx1++) {
        for (int idx2 = 1; idx2 < m + 1; idx2++) {
            // if matching
            if (text1[idx1 - 1] == text2[idx2 - 1])
                cur[idx2] = 1 + prev[idx2 - 1];

            // not matching
            else
                cur[idx2]
                    = 0 + max(cur[idx2 - 1], prev[idx2]);
        }
        prev = cur;
    }

    return cur[m];
}
longestCommonSubsequence(S1, S2);
```

#### Top-Dowm

Time Complexity: O(m * n) where m and n are the string lengths.

Auxiliary Space: O(m * n) Here the recursive stack space is ignored.

```cpp
int lcs(string& X, string& Y, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                          lcs(X, Y, m - 1, n, dp));
}

vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
ll resp = lcs(s1, s2, s1.size(), s2.size(), dp);
```

### LIS

Longest Increasing Subsequence
```cpp
int lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    // Compute optimized LIS values in
    // bottom up manner
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
int n = sizeof(arr) / sizeof(arr[0]);
lis(arr, n); // 5
```

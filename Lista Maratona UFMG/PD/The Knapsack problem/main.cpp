/**
 * https://codeforces.com/problemset/gymProblem/101064/L
 * L. The Knapsack problem
 * PD, programação dinamica, dp
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define print_map(map)                      \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto&(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define log(x) cout << x << endl

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n,
                      int val[], int wt[]) {
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W + 10];
    memset(dp, 0, sizeof(dp));

    // Fill dp[] using above recursive formula
    for (int i = 0; i <= W; i++)
        for (int j = 0; j < n; j++)
            if (wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);

    return dp[W];
}

int main() {
    SPEED;
    int num_itens, capacidade;
    read(num_itens, capacidade);

    int pesos[num_itens];
    int valores[num_itens];
    rep(i, num_itens) {
        read(pesos[i], valores[i]);
    }

    int n = sizeof(valores) / sizeof(valores[0]);
    log(unboundedKnapsack(capacidade, n, valores, pesos));

    return 0;
}

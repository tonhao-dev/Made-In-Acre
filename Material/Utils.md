# Funções úteis do C++

### GCD (Greatest common divisor):
Maior divisor comum
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// OR

__gcd(a, b)
```

### LCM (Least Common Multiple):
MMC, menor múltiplo comum

```cpp
// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
```

### Conversão de tipos

1. stoi: **string** to **int**
2. stol: **string** to **long**
3. stoll: **string** to **long long**
4. stod: **string** to **double**
5. to_string: **number** to **string**

### Produto dos i-th fatoriais

```cpp
// To compute (a * b) % MOD
long long int mulmod(long long int a, long long int b,
                                    long long int mod)
{
    long long int res = 0; // Initialize result
    a = a % mod;
    while (b > 0) {

        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}

// This function computes factorials and
// product by using above function i.e.
// modular multiplication
long long int findProduct(long long int N)
{
    // Initialize product and fact with 1
    long long int product = 1, fact = 1;
    long long int MOD = 1e9 + 7;
    for (int i = 1; i <= N; i++) {

        // ith factorial
        fact = mulmod(fact, i, MOD);

        // product of first i factorials
        product = mulmod(product, fact, MOD);

        // If at any iteration, product becomes
        // divisible by MOD, simply return 0;
        if (product == 0)
            return 0;
    }
    return product;
}

N = 5;
cout << findProduct(N) << endl; // 34560
```

### Josephus

There are N people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.

Given the total number of persons N and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. The task is to choose the person in the initial circle that survives.

```cpp
int Josephus(int N, int k)
{

    // Initialize variables i and ans with 1 and 0
    // respectively.

    int i = 1, ans = 0;

    // Run a while loop till i <= N

    while (i <= N) {

        // Update the Value of ans and Increment i by 1
        ans = (ans + k) % i;
        i++;
    }

    // Return required answer
    return ans + 1;
}

int N = 14, k = 2;
cout << Josephus(N, k) << endl; // 14
```

### Números Primos
#### Verificar se N é primo
Time complexity: O(sqrt(N))
```cpp
bool is_prime(int n) {
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}
```

### Sieve of Eratosthenes
Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.

```cpp
#include <bitset>
#include <iostream>
using namespace std;
bitset<500001> Primes;
void SieveOfEratosthenes(int n)
{
    Primes[0] = 1;
    for (int i = 3; i*i <= n; i += 2) {
        if (Primes[i / 2] == 0) {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}
int main()
{
    int n = 100;
    SieveOfEratosthenes(n);
    for (int i = 1; i <= n; i++) {
        if (i == 2)
            cout << i << ' ';
        else if (i % 2 == 1 && Primes[i / 2] == 0)
            cout << i << ' ';
    }
    // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
    return 0;
}
```

### Binomial Coefficient
A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects more formally, the number of k-element subsets (or k-combinations) of a n-element set.

O coeficiente binomial, também chamado de número binomial, de um número n, na classe k, consiste no número de combinações de n termos, k a k.

```cpp
int binomialCoeff(int n, int r)
{

    if (r > n)
        return 0;
    long long int m = 1000000007;
    long long int inv[r + 1] = { 0 };
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;

    // Getting the modular inversion
    // for all the numbers
    // from 2 to r with respect to m
    // here m = 1000000007
    for (int i = 2; i <= r; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }

    int ans = 1;

    // for 1/(r!) part
    for (int i = 2; i <= r; i++) {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }

    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (int i = n; i >= (n - r + 1); i--) {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}
int n = 5, r = 2;
cout << "Value of C(" << n << ", " << r << ") is "
<< binomialCoeff(n, r) << endl; // Value of C(5, 2) is 10

```

### Conversão de bases numéricas
#### Qualquer base -> decimal
```cpp
string base2 = "1100";
string base8 = "21";
string base10 = "25";
string base16 = "1E";

cout << (stoi(base2, nullptr, 2)) << endl; // 12
cout << (stoi(base8, nullptr, 8)) << endl; // 17
cout << (stoi(base10, nullptr, 10)) << endl; // 25
cout << (stoi(base16, nullptr, 16)) << endl; // 30
```

#### Decimal -> Qualquer base
```cpp
// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Function to convert a given decimal number
// to a base 'base' and
string fromDeci(string& res, int base, int inputNum)
{
    int index = 0; // Initialize index of result

    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0) {
        res.push_back(reVal(inputNum % base));
        index++;
        inputNum /= base;
    }

    // Reverse the result
    reverse(res.begin(), res.end());

    return res;
}
int inputNum = 282, base = 16; string res;
cout << "Equivalent of " << inputNum << " in base "
    << base << " is " << fromDeci(res, base, inputNum)
    << endl; //Equivalent of 282 in base 16 is 11A
```

### Partição de um número
Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.

Time Complexity: O(2^n)

```cpp
class Solution {
public:
    vector<int> temp;
    void solve(vector<int> a, vector<vector<int> >& v,
               int idx, int sum, int n)
    {
        // first base case if sum=n we can store vector in a
        // vector
        if (sum == n) {
            v.push_back(temp);
            return;
        }
        // if idx < 0 return
        if (idx < 0) {
            return;
        }
        // not take condition
        solve(a, v, idx - 1, sum, n);
        if (sum < n) {
            temp.push_back(a[idx]);
            // this is main condition where we can take one
            // element many times
            solve(a, v, idx, sum + a[idx], n);
            temp.pop_back();
        }
    }
    vector<vector<int> > UniquePartitions(int n)
    {
        vector<int> a;
        // vector to store elements from 1 to n
        for (int i = 1; i <= n; i++) {
            a.push_back(i);
        }
        vector<vector<int> > v;
        // call solve to get answer
        solve(a, v, n - 1, 0, n);
        reverse(v.begin(), v.end());
        return v;
    }
};
// using
vector<vector<int> > ans = ob.UniquePartitions(4);
cout << "for 4\n";
for (auto i : ans) {
    for (auto j : i) {
        cout << j << " ";
    }
    cout << "\n";
}
```

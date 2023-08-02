/**
 * [Nome da questão]
 * beecrowd | [Número]
 * [Link]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define db(x) cout << #x << ": " << x << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cm(map)                             \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);

    ll n =0 ,r =0,o = 0,z =0,e = 0, lenght;
    cin >> lenght;
    string letters;
    cin.ignore();
    getline(cin, letters);

    foreach(letter, letters) {
        switch (letter)
        {
        case 'z':
            z++;
            continue;
        case 'n':
            n++;
            continue;
        case 'o':
            o++;
            continue;
        case 'e':
            e++;
            continue;
        default:
            r++;
            continue;
        }
    }

    ll numbersOfOne = n, numbersOfZero = e-n;

    rep(i, numbersOfOne) {
        cout << 1 << " ";
    }

    rep(i, numbersOfZero) {
        cout << 0 << " ";
    }
    return 0;
}

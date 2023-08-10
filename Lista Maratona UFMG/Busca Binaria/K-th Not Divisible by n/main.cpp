/**
 * https://codeforces.com/contest/1352/problem/C
 * binary search, busca binaria, math, matematica
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = " << ;              \
        for (auto &it : vector) cout << it << " "; \
        cout << endl;                              \
    }
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
#define MOD 1e9 + 7
#define log(x) cout << x << endl
#define read(x) cin >> x

#define MAX_N 1e10

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

ll binary_search(ll inicio, ll fim, ll n, ll k) {
    ll meio;

    ll resp = -1;
    while (inicio < fim) {
        meio = (inicio + fim) / 2;

        if (meio % n == 0) {
            meio--;
        }

        ll kth_position = meio - (meio / n);

        if (kth_position == k) {
            resp = meio;
            break;
        };

        if (kth_position > k) {
            fim = meio;
        } else {
            inicio = meio + 1;
        }
    }

    return resp;
}

int main(int argc, char **argv) {
    SPEED;
    ll t;
    read(t);
    rep(ti, t) {
        ll n, k;
        cin >> n >> k;

        log(binary_search(1, MAX_N, n, k));
    }

    return 0;
}

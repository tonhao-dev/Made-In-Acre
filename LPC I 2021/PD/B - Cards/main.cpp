
/**
 * https://vjudge.net/contest/576477#problem/C
 * PD, programação dinamica, dp
 */

#include <bits/stdc++.h>

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vstr;
typedef vector<vll> vvll;

#define print_vector(vector) \
    for (auto x : vector)    \
        cout << x << " ";    \
    cout << endl
#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define endl "\n"
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll N;
vll cartas;
ll memo[10000][10000];

ll dp(ll esq, ll dir, int vez) {
    if (esq > dir) {
        return 0;
    }

    ll &p = memo[dir][esq];
    if (p != -1) return p;

    if (vez == 0) {
        return p = max(cartas[esq] + dp(esq + 1, dir, 1), cartas[dir] + dp(esq, dir - 1, 1));
    } else {
        return p = min(dp(esq + 1, dir, 0), dp(esq, dir - 1, 0));
    }
}

int main() {
    speed;
    while (cin >> N) {
        cartas.resize(N);
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) memo[i][j] = -1;
        }

        for (auto &i : cartas) cin >> i;

        cout << dp(0, N - 1, 0) << endl;
    }

    return 0;
}

/**
 * Problema A - Os Mais Rápidos de Todos os Tempos
 * Busca binária
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG) cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)                           \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define dbmap(map)                          \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, p;
vector<ll> comp;

bool consegue(ll min) {
    ll total = 0;
    for(auto c : comp) {
        if(total >= p) return true;
        total += (min / c);
    }

    return total >= p;
}

int main(int argc, char** argv) {
    SPEED;

    cin >> n >> p;

    comp.resize(n);
    for(auto &i : comp) cin >> i;

    ll r = 0, l = 200000000000000 + 20;
    while(r < l) {
        ll mid = (r + l) / 2;
        if(consegue(mid)) {
            l = mid;
        } else {
            r = mid + 1;
        }
    }

    cout << r << endl;

    return 0;
}

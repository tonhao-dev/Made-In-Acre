/**
 * [Link]
 * [Assuntos]
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

int main() {
    int NC = 0;
    int n = 0;
    int k = 0;
    int i = 0;
    int j = 0;
    int x = 0;

    cin >> NC;

    for (i = 0; i < NC; i++) {
        cin >> n >> k;

        int num_vivos = n;
        vector<bool> soldado(n, true);

        int i = 0;
        int contados = k;
        while (num_vivos > 1) {
            for (int j = i, contados = k; contados > 0; j++) {
                if (j == n) j = 0;
                if (soldado[j]) contados--;
                if (contados == 0) {
                    soldado[j] = false;
                    num_vivos--;
                    i = j;
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (soldado[j]) {
                cout << "Case " << i + 1 << ": " << j + 1 << endl;
            }
        }
    }

    return 0;
}

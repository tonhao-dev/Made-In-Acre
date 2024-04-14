/**
 * [Link]
 * [Título da questão]
 * [Assuntos]
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

void solve() {
    int n, c, d, min_value = INF;

    cin >> n >> c >> d;

    vector<vi> square(n + 1, vi(n + 1));
    map<int, int> valores;

    for (int i = 1; i <= n * n; i++) {
        int val;
        cin >> val;

        valores[val]++;
        min_value = min(min_value, val);
    }

    valores[min_value]--;
    square[1][1] = min_value;

    // linha
    for (int i = 2; i <= n; i++) {
        square[i][1] = square[i - 1][1] + c;
        valores[square[i][1]]--;
    }
    // coluna
    for (int i = 2; i <= n; i++) {
        square[1][i] = square[1][i - 1] + d;
        valores[square[1][i]]--;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            square[i][j] = square[i][j - 1] + d;
            valores[square[i][j]]--;
        }
    }

    for (auto e : valores) {
        if (e.second != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}

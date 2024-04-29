/**
 * https://judge.beecrowd.com/pt/problems/view/1897
 * 1897
 * Jogo Esperto
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
    int n, m;
    cin >> n >> m;

    if (n == m) {
        cout << 0 << endl;
        return;
    }

    queue<pair<int, int>> fila;
    set<int> memo;
    fila.push({n, 1});
    int ans = 0;

    while (fila.front().f != m) {
        auto atual = fila.front();
        fila.pop();

        if (memo.find(atual.f) != memo.end()) continue;

        if (atual.f * 2 == m || atual.f * 3 == m || atual.f / 2 == m || atual.f / 3 == m || atual.f + 7 == m || atual.f - 7 == m) {
            ans = atual.s;
            break;
        }

        memo.insert(atual.f);

        fila.push({atual.f * 2, atual.s + 1});
        fila.push({atual.f * 3, atual.s + 1});
        fila.push({atual.f / 2, atual.s + 1});
        fila.push({atual.f / 3, atual.s + 1});
        fila.push({atual.f + 7, atual.s + 1});
        fila.push({atual.f - 7, atual.s + 1});
    }

    cout << ans << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}

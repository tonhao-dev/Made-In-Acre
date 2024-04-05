/**
 * https://neps.academy/br/exercise/57
 * Toca do Saci
 * Grafos, DFS
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

int n, m;
vector<pii> movimentos = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valido(int i, int j) {
    return (i >= 0 && i < n) && (j >= 0 && j < m);
}

void solve() {
    cin >> n >> m;

    vector<vi> toca(n, vi(m));

    pii emilia, saida;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> toca[i][j];

            if (toca[i][j] == 2) emilia = {i, j};
            if (toca[i][j] == 3) saida = {i, j};
        }
    }

    int resp = 1;
    stack<tuple<int, int, int>> pilha;
    pilha.push(make_tuple(emilia.f, emilia.s, 0));
    set<pii> visitado;
    visitado.insert(emilia);

    while (!pilha.empty()) {
        int i, j, dist;
        tie(i, j, dist) = pilha.top();
        pilha.pop();

        if (toca[i][j] == 3) {
            resp = dist + 1;
            break;
        };

        for (auto mov : movimentos) {
            pii prox_posicao = {i + mov.f, j + mov.s};

            if (!valido(prox_posicao.f, prox_posicao.s)) continue;
            if (visitado.find({prox_posicao.f, prox_posicao.s}) != visitado.end()) continue;
            if (toca[prox_posicao.f][prox_posicao.s] == 0) continue;

            visitado.insert({i, j});
            pilha.push(make_tuple(prox_posicao.f, prox_posicao.s, dist + 1));
        }
    }

    cout << resp << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}

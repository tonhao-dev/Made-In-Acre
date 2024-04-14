/**
 * https://codeforces.com/problemset/problem/377/A
 * A. Maze
 * Grafos, dfs
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

int n, m, k, count_empty;

bool ehValido(int i, int j) {
    return ((i >= 1 && i <= n) && (j >= 1 && j <= m));
}

void dfs(vector<string>& maze, pii coord) {
    set<pii> visitado;
    stack<pii> pilha;

    visitado.insert(coord);
    pilha.push(coord);
    maze[coord.f][coord.s] = '0';

    while (!pilha.empty() && visitado.size() < count_empty - k) {
        pii atual = pilha.top();
        pilha.pop();

        if (ehValido(atual.f - 1, atual.s) && visitado.find({atual.f - 1, atual.s}) == visitado.end() && maze[atual.f - 1][atual.s] == '.') {
            pilha.push({atual.f - 1, atual.s});
            visitado.insert({atual.f - 1, atual.s});
            maze[atual.f - 1][atual.s] = '0';
        }

        if (visitado.size() >= count_empty - k) break;

        if (ehValido(atual.f, atual.s + 1) && visitado.find({atual.f, atual.s + 1}) == visitado.end() && maze[atual.f][atual.s + 1] == '.') {
            pilha.push({atual.f, atual.s + 1});
            visitado.insert({atual.f, atual.s + 1});
            maze[atual.f][atual.s + 1] = '0';
        }

        if (visitado.size() >= count_empty - k) break;

        if (ehValido(atual.f + 1, atual.s) && visitado.find({atual.f + 1, atual.s}) == visitado.end() && maze[atual.f + 1][atual.s] == '.') {
            pilha.push({atual.f + 1, atual.s});
            visitado.insert({atual.f + 1, atual.s});
            maze[atual.f + 1][atual.s] = '0';
        }

        if (visitado.size() >= count_empty - k) break;

        if (ehValido(atual.f, atual.s - 1) && visitado.find({atual.f, atual.s - 1}) == visitado.end() && maze[atual.f][atual.s - 1] == '.') {
            pilha.push({atual.f, atual.s - 1});
            visitado.insert({atual.f, atual.s - 1});
            maze[atual.f][atual.s - 1] = '0';
        }
    }
}

void solve() {
    cin >> n >> m >> k;

    vector<string> maze(n + 2);
    count_empty = 0;

    string parede;
    for (int i = 0; i < m + 2; i++) {
        parede += '#';
    }
    maze[0] = parede;
    maze[n + 1] = parede;

    pii start = {-1, -1};
    for (int i = 1; i <= n; i++) {
        string linha;
        cin >> linha;
        maze[i] = '#' + linha + '#';

        for (int j = 1; j <= m; j++) {
            if (maze[i][j] == '.') {
                start = {i, j};
                count_empty++;
            }
        }
    };

    dfs(maze, start);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (maze[i][j] == '0')
                cout << '.';
            else if (maze[i][j] == '.')
                cout << 'X';
            else
                cout << maze[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}

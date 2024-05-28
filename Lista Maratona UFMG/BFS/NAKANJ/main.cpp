/**
 * https://judge.beecrowd.com/pt/problems/view/1100
 * Grafos, bfs, backtracking
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) cout << #x << ": " << x.f << ", " << x.s << endl
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

vector<pii> movimentos = {{2, 1},
                          {1, 2},
                          {-1, 2},
                          {-2, 1},
                          {-2, -1},
                          {-1, -2},
                          {1, -2},
                          {2, -1}};

pii to_coord(string raw) {
    map<char, int> letter = {
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3},
        {'e', 4},
        {'f', 5},
        {'g', 6},
        {'h', 7},
    };

    return {letter[raw[0]], 8 - (raw[1] - '0')};
}

bool ehValido(int i, int j) {
    return ((i >= 0 && i <= 7) && (j >= 0 && j <= 7));
}

int bfs(pii origin, pii destination) {
    set<pii> visited;
    queue<tuple<int, int, int>> fila;

    fila.push(make_tuple(origin.f, origin.s, 0));

    while (!fila.empty()) {
        int i, j, peso;
        tuple<int, int, int> atual = fila.front();
        fila.pop();

        tie(i, j, peso) = atual;

        if (i == destination.f && j == destination.s) return peso;

        for (auto mov : movimentos) {
            if (!ehValido(i + mov.f, j + mov.s)) continue;
            if (visited.count({i + mov.f, j + mov.s}) != 0) continue;

            fila.push(make_tuple(i + mov.f, j + mov.s, peso + 1));
        }
    }

    return 0;
}

void solve() {
    string from, to;
    while (cin >> from >> to) {
        pii ij_origin = to_coord(from), ij_target = to_coord(to);

        cout << bfs(ij_origin, ij_target) << endl;
    }
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}

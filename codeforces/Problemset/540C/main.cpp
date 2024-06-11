/**
 * https://codeforces.com/problemset/problem/540/C
 * C. Ice Cave
 * Grafo, graph, dfs, grid
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

int n, m;

const vector<pii> moves = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

bool ehValid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

bool dfs(vector<vi>& grid, pii current, pii target) {
    if (current.f == target.f && current.s == target.s) return true;

    grid[current.f][current.s] = -1;

    bool findedTarget = false;
    for (auto move : moves) {
        int i = current.f + move.f, j = current.s + move.s;

        if (!ehValid(i, j)) continue;

        if (grid[i][j] != 2 && !(i == target.f && j == target.s)) continue;

        findedTarget |= dfs(grid, {i, j}, target);

        if (findedTarget) return true;
    }

    return findedTarget;
}

int countIntactNeighbors(vector<vi>& grid, int x, int y) {
    int intactNeighborCount = 0;
    for (auto mov : moves) {
        int i = x + mov.f, j = y + mov.s;
        if (!ehValid(i, j)) continue;

        intactNeighborCount += grid[i][j] == 2;
    }

    return intactNeighborCount;
}

bool areNeighbors(vector<vi>& grid, pii start, pii end) {
    for (auto mov : moves) {
        int i = start.f + mov.f, j = start.s + mov.s;
        if (!ehValid(i, j)) continue;

        if (i == end.f && j == end.s) return true;
    }

    return false;
}

void solve() {
    cin >> n >> m;

    vector<vi> grid(n, vi(m));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < m; j++) {
            grid[i][j] = line[j] == '.' ? 2 : 1;
        }
    };

    pii start, end;
    cin >> start.f >> start.s;
    cin >> end.f >> end.s;

    start.f--;
    start.s--;
    end.f--;
    end.s--;

    int intactNeighborCount = countIntactNeighbors(grid, end.f, end.s);

    if (start.f == end.f && start.s == end.s && intactNeighborCount >= 1) {
        cout << "YES" << endl;
        return;
    }

    if (start.f == end.f && start.s == end.s && intactNeighborCount == 0) {
        cout << "NO" << endl;
        return;
    }

    if (areNeighbors(grid, start, end) && grid[end.f][end.s] == 1) {
        cout << "YES" << endl;
        return;
    }

    if (areNeighbors(grid, start, end) && grid[end.f][end.s] == 2 && intactNeighborCount >= 1) {
        cout << "YES" << endl;
        return;
    }

    if (grid[end.f][end.s] == 2 && intactNeighborCount < 2) {
        cout << "NO" << endl;
        return;
    }

    if (grid[end.f][end.s] == 1 && intactNeighborCount < 1) {
        cout << "NO" << endl;
        return;
    }

    bool hasPath = dfs(grid, start, end);

    if (!hasPath) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}

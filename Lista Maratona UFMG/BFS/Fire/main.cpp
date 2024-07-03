/**
 * https://open.kattis.com/problems/fire2
 * Fire
 * Grafos, graph, bfs, grid
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x)  \
    if (DEBUG) \
    cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG)    \
    cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)          \
    {                             \
        cout << #vector << " = "; \
        for (auto &it : vector)   \
            cout << it << " ";    \
        cout << endl;             \
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
const int MAXN = 1010;

int width, height;
int timeToPersonOut, timeToFireOut;
vector<string> grid(MAXN);

const vector<pii> moves = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

bool isValidCoord(int i, int j) {
    return (i >= 0 && i < height) && (j >= 0 && j < width);
}

int bfs(queue<pair<int, pii>> &q) {
    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        if (front.f > timeToPersonOut) continue;

        for (auto mov : moves) {
            int x = front.s.f + mov.f, y = front.s.s + mov.s;

            if (!isValidCoord(x, y))
                return front.f + 1;

            if (grid[x][y] == '#' || grid[x][y] == '*')
                continue;

            q.push({front.f + 1, {x, y}});
        }
    }

    return -1;
}

void solve() {
    queue<pair<int, pii>> people;
    queue<pair<int, pii>> fire;

    cin >> width >> height;

    for (int i = 0; i < height; i++) {
        cin >> grid[i];

        for (int j = 0; j < width; j++) {
            if (grid[i][j] == '@') {
                people.push({0, {i, j}});
            }

            if (grid[i][j] == '*') {
                fire.push({0, {i, j}});
            }
        }
    }

    timeToPersonOut = INF;
    timeToPersonOut = bfs(people);

    if (timeToPersonOut == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    timeToFireOut = bfs(fire);

    if (timeToFireOut <= timeToPersonOut) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << timeToPersonOut << endl;
}

int main(int argc, char **argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
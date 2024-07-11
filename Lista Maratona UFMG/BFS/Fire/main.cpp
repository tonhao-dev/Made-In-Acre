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
vector<string> grid(MAXN);

const vector<pii> moves = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

bool isValidCoord(int i, int j) {
    return (i >= 0 && i < height) && (j >= 0 && j < width);
}

int people_bfs(queue<pair<int, pii>> &people) {
    set<pii> visited;
    visited.insert(people.front().s);
    while (!people.empty()) {
        auto person = people.front();
        people.pop();

        for (auto mov : moves) {
            int x = person.s.f + mov.f, y = person.s.s + mov.s;

            if (!isValidCoord(x, y))
                return person.f + 1;

            if (visited.find({x, y}) != visited.end())
                continue;

            if (grid[x][y] == '#' || grid[x][y] == '*')
                continue;

            people.push({person.f + 1, {x, y}});
            visited.insert({x, y});
        }
    }

    return -1;
}

int fire_bfs(queue<pair<int, pii>> fire, set<pii> &visited_fire) {
    int ans = INF;
    while (!fire.empty()) {
        auto currentFire = fire.front();
        fire.pop();

        for (auto mov : moves) {
            int x = currentFire.s.f + mov.f, y = currentFire.s.s + mov.s;

            if (!isValidCoord(x, y)) {
                ans = min(ans, currentFire.f + 1);
                continue;
            }

            if (visited_fire.find({x, y}) != visited_fire.end()) continue;

            if (grid[x][y] == '#')
                continue;

            if (grid[x][y] == '*')
                continue;

            fire.push({currentFire.f + 1, {x, y}});
            visited_fire.insert({x, y});
        }
    }

    return ans;
}

void solve() {
    queue<pair<int, pii>> people;
    queue<pair<int, pii>> fire;
    set<pii> visited_fire;

    cin >> width >> height;

    for (int i = 0; i < height; i++) {
        cin >> grid[i];

        for (int j = 0; j < width; j++) {
            if (grid[i][j] == '@') {
                people.push({0, {i, j}});
            }

            if (grid[i][j] == '*') {
                fire.push({0, {i, j}});
                visited_fire.insert({i, j});
            }
        }
    }

    int timeToPersonOut = people_bfs(people);

    if (timeToPersonOut == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int timeToFireOut = fire_bfs(fire, visited_fire);

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
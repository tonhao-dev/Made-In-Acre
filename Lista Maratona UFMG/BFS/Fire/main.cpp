/**
 * https://open.kattis.com/problems/fire2
 * Fire
 * Grafos, graph, bfs, grid
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
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

int bfs(queue<pair<int, pii>> &fire, queue<pair<int, pii>> &people) {
    while (!people.empty()) {
        int currentTime = people.front().f;
        db(currentTime);

        while (!people.empty() && currentTime == people.front().f) {
            auto person = people.front();
            people.pop();

            db(grid[person.s.f][person.s.s]);
            if (grid[person.s.f][person.s.s] != '@') continue;

            for (auto mov : moves) {
                int x = person.s.f + mov.f, y = person.s.s + mov.s;

                if (!isValidCoord(x, y))
                    return person.f + 1;

                if (grid[x][y] != '.')
                    continue;

                people.push({person.f + 1, {x, y}});
                grid[x][y] = '@';
            }
        }

        // for(int i=0;i<height;i++) {
        //     for(int j=0;j<width; j++) {
        //         cout << grid[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        while (!fire.empty() && fire.front().f == currentTime) {
            auto currentFire = fire.front();
            fire.pop();
            for (auto mov : moves) {
                int x = currentFire.s.f + mov.f, y = currentFire.s.s + mov.s;

                if (!isValidCoord(x, y))
                    continue;

                if (grid[x][y] == '#')
                    continue;

                if (grid[x][y] == '*')
                    continue;

                fire.push({currentFire.f + 1, {x, y}});
                grid[x][y] = '*';
            }
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

    int timeToOut = bfs(fire, people);

    if (timeToOut == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << timeToOut << endl;
}

int main(int argc, char **argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

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
    int n, m, k;
    cin >> n >> m >> k;

    if (m == 1) {
        cout << "NO" << endl;
        return;
    }

    vector<int> ribbon(n);
    int color = 1;
    for (auto& part : ribbon) {
        part = (color++ % m);
    }

    vector<int> most_repetitions(100);
    for (auto part : ribbon) {
        most_repetitions[part]++;
    }

    int most_duplicated = INT_MIN;
    for (auto part : most_repetitions) {
        most_duplicated = max(most_duplicated, part);
    }

    if (n - most_duplicated > k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}

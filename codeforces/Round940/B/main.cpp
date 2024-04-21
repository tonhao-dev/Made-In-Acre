/**
 * https://codeforces.com/contest/1957/problem/B
 * B. A BIT of a Construction
 * bitwise
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
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << k << endl;
        return;
    }

    vector<int> resp;
    ll sum = 0;
    for (int i = 30; i >= 0; i--) {
        int pot = 1 << i;

        if (pot - 1 == k) {
            cout << k << " ";
            for (int i = 0; i < n - 1; i++) {
                if (i == n - 2) {
                    cout << 0 << endl;
                    return;
                }
                cout << 0 << " ";
            }
        }

        if (pot < k) {
            resp.pb(pot);
            sum += pot;

            pot = 1 << (i - 1);
            resp.pb(pot - 1);
            sum += pot;

            break;
        }
    }

    if (k % 2 == 0) {
        for (int i = 0; i < n - 2; i++) resp.pb(0);
    } else {
        for (int i = 0; i < n - 2; i++) resp.pb(1);
    }

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << resp[i] << endl;
            break;
        }

        cout << resp[i] << " ";
    }
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vstr;
typedef vector<vll> vvll;

#define endl "\n"
#define print_vector(vector) \
    for (auto x : vector)    \
        cout << x << " ";    \
    cout << endl
#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int resp = INT_MAX;
    int count_before = 1;
    int borda = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] != borda) {
            resp = min(resp, count_before);
            count_before = 0;
            continue;
        }

        count_before++;
    }

    borda = a[n - 1];
    count_before = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != borda) {
            resp = min(resp, count_before);
            count_before = 0;
            continue;
        }

        count_before++;
    }

    if (resp == INT_MAX)
        cout << -1 << endl;
    else
        cout << resp << endl;
}

int main() {
    speed;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

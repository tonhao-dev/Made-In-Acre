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

vector<pair<pii, int>> ranges;

// WA
void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(k + 1, 0);
    vector<int> b(k + 1, 0);

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    vector<int> preffix_tempo;
    preffix_tempo.pb(0);
    for (int i = 1; i <= k; i++) {
        preffix_tempo.pb(b[i] + preffix_tempo[i - 1]);
    }

    while (q--) {
        int query;
        cin >> query;

        auto it = lower_bound(all(a), query);
        int pos = it - a.begin();

        double velocidade = (double)(a[pos] - a[pos - 1]) / (double)(b[pos] - b[pos - 1]);
        double ans = b[pos - 1] + (query - a[pos - 1]) / (double)velocidade;

        cout << fixed << setprecision(0);
        cout << floor(ans) << " ";
    }
    cout << endl;
}

int main() {
    speed;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

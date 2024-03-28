/**
 *  Problema G - Museu de flores
 * Guloso, implementação
 */

#include <bits/stdc++.h>

using namespace std;

#define speed                   \
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
  for (auto x : vector)      \
    cout << x << " ";        \
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

int n, m;
vector<pii> intervalos;

ll calcula_intervalo(vector<int>& arr, int i) {
    ll acc_tulipa = 0, acc_rosita = 0;
    vector<ll> tulipa, rosita;
    auto intervalo = intervalos[i];

    for(int begin = intervalo.f - 1; begin < intervalo.s; begin++) {
        if(arr[begin] == 1) {
            if(acc_tulipa) {
                tulipa.pb(acc_tulipa);
                acc_tulipa = 0;
            }
            acc_rosita++;
        } else {
            if(acc_rosita) {
                tulipa.pb(acc_rosita);
                acc_rosita = 0;
            }
            acc_tulipa++;
        }
    }

    ll total_tulipa = !tulipa.empty();
    for(auto t : tulipa) {
        total_tulipa *= t;
    }

    ll total_rosita = !rosita.empty();
    for(auto r : rosita) {
        total_rosita *= r;
    }

    return (total_rosita + total_tulipa);
}

ll calcular(vector<int>& arr) {
    ll ans = 0;

    for(int i = 0; i < m; i++) {
        ans += calcula_intervalo(arr, i);
    }

    return ans;
}

ll ans = 0;

void generateAllBinaryStrings(vector<int> arr, int i) {
    if (i == n) {
        auto calc =  calcular(arr);

        string produce;
        for(auto a : arr) produce += a ? '1' : '0';

        ans = max(ans, calc);

        cout << produce << endl;
        cout << calc << endl;
        cout << endl;

        return;
    }

    arr[i] = 0;
    generateAllBinaryStrings(arr, i + 1);

    arr[i] = 1;
    generateAllBinaryStrings(arr, i + 1);
}

int main() {
    cin >> n >> m;
    vector<int> arr(n, 0);
    intervalos.resize(m);

    for(auto &i : intervalos) cin >> i.f >> i.s;

    generateAllBinaryStrings(arr, 0);

    cout << ans << endl;

    return 0;
}

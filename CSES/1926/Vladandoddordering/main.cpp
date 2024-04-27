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


int main()
{
  speed;
  int t; cin >> t;

  int impar[1000000000];
  int contador = 0;
  for(int i = 1; i <= 1000000000; i += 2) {
   impar[contador] = i;
   contador++;
  }
   cout << impar[1] << endl;

//   while(t--) {
//     ll n, k; cin >> n >> k;

//     int metade = ceil((double)n / 2.0);
//     db(metade);
//     if(k <= metade) {
//       cout << impar[k] << endl;
//       continue;
//     }

//     ll ki = metade + 1;

//     for(int i = 1; i < 50; i++) {
//       for (ll j = (ll)pow(2, i); j <= n; j += (ll)pow(2, i + 1)) {
//         cout << j << " ";
//         if(ki >= k) {
//           cout << j << endl;
//           break;
//         }
//         ki++;
//       }
//       cout << endl;
//       if(ki >= k) break;
//     }
//     cout << endl;
//   }

  return 0;
}

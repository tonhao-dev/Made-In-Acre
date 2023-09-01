#include <bits/stdc++.h>

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

using namespace std;
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
#define endl "\n"
#define f first
#define s second

ll qtd;
vll alturas((5*1e4) +1);

bool forma_lado_direito(ll altura, ll i) {
  for(; i < qtd; i++) {
    if(altura == 0) return true;

    if(alturas[i] >= altura) altura--;
    else return false;
  }

  return altura == 0;
}

bool forma_lado_esquerdo(ll altura, ll i) {
  for(; i >= 0; i--) {
    if(altura == 0) return true;
    if(alturas[i] >= altura) altura--;
    else return false;
  }


  return altura == 0;
}

bool consegue(ll altura) {
  ll i = altura;

  for(; i < qtd; i++) {
    if(alturas[i] < altura) continue;

    if(forma_lado_esquerdo(altura - 1, i - 1) && forma_lado_direito(altura - 1, i + 1)) return true;
  }

  return false;
}

int main()
{
  speed;
  cin >> qtd;

  for(ll i = 0; i < qtd; i++) cin >> alturas[i];

  ll l = 1, r = 5*1e4, ans = 1;
  while(l < r) {
    ll mid = (l + r) / 2;

    if(consegue(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid;
    }
  }

  cout << ans << endl;


  return 0;
}

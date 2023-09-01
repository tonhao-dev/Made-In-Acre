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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int verificar2(int ano, int b, int c) {
  if((ano - b) == 2016) return 1;
  if((ano + b) == 2016) return 1;
  if((ano - c) == 2016) return 1;
  if((ano + c) == 2016) return 1;

  if(((ano - b) - c) == 2016) return 1;
  if(((ano - b) + c) == 2016) return 1;
  if(((ano + b) + c) == 2016) return 1;
  if(((ano + b) - c) == 2016) return 1;

  if(((ano - c) - b) == 2016) return 1;
  if(((ano - c) + b) == 2016) return 1;
  if(((ano + c) + b) == 2016) return 1;
  if(((ano + c) - b) == 2016) return 1;

  return 0;
}

int verificar(int a, int b, int c) {
  return verificar2(2016 - a, b, c) || verificar2(2016 + a, b, c);
}


int main()
{
  speed;
  vi voltas(3);
  for(auto &i : voltas) cin >> i;
  sort(all(voltas));

  do {
    if(verificar(voltas[0], voltas[1], voltas[2])) {
      cout << 'S' << endl;
      return 0;
    }
  } while(next_permutation(all(voltas)));

  cout << 'N' << endl;

  return 0;
}

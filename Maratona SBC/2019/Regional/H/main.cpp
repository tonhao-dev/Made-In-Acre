/**
 * H - Hora da Corrida
 * Iniciante
 */

#include <bits/stdc++.h>

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vstr;
typedef vector<vll> vvll;

#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define endl "\n"
#define f first
#define s second

int main()
{
  speed;
  ll V, N; cin >> V >> N;

  ll total_placas = V * N;

  ll perc = 10;
  int flag = 0;
  while(perc < 100) {
    if(flag) cout << " ";
    flag = 1;

    cout << (ll)ceil((total_placas * perc) / 100.00);
    perc += 10;
  }
  cout << endl;

  return 0;
}

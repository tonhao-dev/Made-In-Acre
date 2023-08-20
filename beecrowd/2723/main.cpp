/**
 * 2723 - Equilibrando Presentes - https://www.beecrowd.com.br/judge/pt/problems/view/2723
 * programação dinâmica - pd
 */

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

ll N;
vll presentes;

int memo[10001][21][21];

bool dp(ll presente, pll pesos) {
  if(abs(pesos.f - pesos.s) > 5) return false;
  if(presente == N) return true;

  if(pesos.f >= 10 && pesos.s >= 10) {
    pesos = mp(pesos.f - 10, pesos.s - 10);
  }

  int &p = memo[presente][pesos.f][pesos.s];
  if(p != -1) return p;

  return p = dp(presente + 1, { pesos.f, pesos.s + presentes[presente] }) ||  dp(presente + 1, { pesos.f + presentes[presente], pesos.s });
}

int main()
{
  speed;
  ll qtd; cin >> qtd;

  while(qtd--) {
    cin >> N;
    presentes.resize(N);
    for(auto &i : presentes) cin >> i;
    memset(memo, -1, sizeof(memo));
    cout << (dp(0, {0, 0}) ? "Feliz Natal!" : "Ho Ho Ho!") << endl;
  }

  return 0;
}

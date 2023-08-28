/**
 * Botas Perdidas - https://www.beecrowd.com.br/judge/pt/problems/view/1245
 * Adhoc, simulação
 */

#include <bits/stdc++.h>

#define speed                     \
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
    for (auto x : vector)    \
        cout << x << " ";    \
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

int main()
{
  speed;
  int n;
  while (cin >> n)
  {
    vector<pair<int, int>> botas(31, {0, 0});

    while (n--)
    {
      int tamanho;
      char pe;

      cin >> tamanho >> pe;

      if (pe == 'D')
      {
        botas[tamanho - 30].second++;
      }
      else
      {
        botas[tamanho - 30].first++;
      }
    }

    int total = 0;
    for (int i = 0; i < botas.size(); i++)
    {
      total += min(botas[i].first, botas[i].second);
    }

    cout << total << endl;
  }

  return 0;
}

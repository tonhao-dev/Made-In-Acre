/**
 * A - Achando os Monótonos Não-Triviais Maximais
 * Iniciante, string
 */

#include <bits/stdc++.h>

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define lll long long int
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

int main()
{
  speed;
  int n;
  cin >> n;

  cin.ignore();
  string s;
  getline(cin, s);

  bool tah_contando = false;
  ll ans = 0;
  for (ll i = 0; i < s.size(); i++)
  {
    if (tah_contando && s[i] != 'a')
    {
      tah_contando = false;
      continue;
    }

    if (tah_contando && s[i] == 'a')
      ans++;

    if (i + 1 == s.size())
      break;

    if (s[i] == 'a' && s[i + 1] == 'a' && !tah_contando)
    {
      ans++;
      tah_contando = true;
    };
  }

  cout << ans << endl;
  return 0;
}

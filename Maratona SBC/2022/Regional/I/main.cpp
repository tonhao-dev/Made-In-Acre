/**
 * I - Interceptando Informações
 * Iniciante
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

  vector<int> bin(8);
  bool errado = false;

  for (int i = 0; i < bin.size(); i++)
  {
    cin >> bin[i];
    if (bin[i] == 9)
      errado = true;
  }

  cout << (errado ? "F" : "S") << endl;

  return 0;
}

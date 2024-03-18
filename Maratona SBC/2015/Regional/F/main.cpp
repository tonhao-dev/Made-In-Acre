/**
 * Problema: F - Fatorial
 * Assunto: Coin change (Programação Dinâmica)/Guloso
 */

#include <bits/stdc++.h>

#define _                       \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define INF 1000000007

using namespace std;

int main()
{
  _ long long n;
  cin >> n;

  vector<long long> fat(11, 0);
  fat[0] = 1;
  for (int i = 1; i < fat.size(); i++)
  {
    fat[i] = (i * fat[i - 1]);
  }

  int ans = 0;
  long long total = 0;
  for (int i = fat.size() - 1; i >= 0;)
  {

    if ((total + fat[i]) <= n)
    {
      total += fat[i];
      ans++;
    }
    else
    {
      i--;
    }

    if (total == n)
    {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

float a = 3.223223;
double a = 3.223223223223;

// https://judge.beecrowd.com/pt/problems/view/2355

int main() {
  speed;
  double razao_alemanha = 90.0 / 7.0;

  while(true) {
    ll n; cin >> n;
    if(n == 0) break;

    ll brasil = n / 90;
    ll alemanha = ceil((double)n / razao_alemanha);
    cout << "Brasil " << brasil << " x ";
    cout << "Alemanha " << alemanha;
    cout << endl;
  }

  return 0;
}
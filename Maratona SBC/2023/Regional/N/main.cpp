/**
 * N - Números Virados
 * Simulação, Soma de Prefixos
 */

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

ll n, k, l, soma_a, soma_b;
vector<ll> a, b;

multiset<ll> melhores, reserva;

void printset(multiset<ll>& mult) {
  for(auto b : mult) {
    cout << b << " ";
  }
  cout << endl;
}

void inserir(ll valor) {
  if(melhores.size() < l) {
    melhores.insert(valor);
    soma_b += valor;
    return;
  }

  auto menor = melhores.begin();
  if(*menor >= valor) {
    reserva.insert(valor);
    return;
  }

  soma_b -= *menor;
  reserva.insert(*menor);

  soma_b += valor;
  melhores.erase(menor);
  melhores.insert(valor);
}

void remover(ll valor) {
  auto nos_reserva = reserva.find(valor);

  if(nos_reserva != reserva.end()) {
    reserva.erase(nos_reserva);
    return;
  }

  soma_b -= valor;

  melhores.erase(melhores.find(valor));

  if(!reserva.empty()) {
    auto maior = prev(reserva.end());

    melhores.insert(*maior);
    reserva.erase(maior);

    soma_b += *maior;
    return;
  }

  if(melhores.empty()) return;
  soma_b += *prev(melhores.end());
}

void bootstrap() {
  int esq = n - k;
  for(int i = esq; i < n; i++) {
    soma_a += a[i];
    inserir(b[i]);
  }
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  soma_a = soma_b = 0;

  for(auto &i : a) cin >> i;
  for(auto &i : b) cin >> i;

  cin >> k >> l;

  if(n == 1) {
    cout << a[0] + b[0] << endl;
    return 0;
  }

  ll ans = 0;
  bootstrap();

  int esq = n - k, dir = n - 1;
  bool passei = false, passei_dois = false;
  while(!passei_dois) {
    if(passei) passei_dois = true;
    ans = max(ans, soma_a + soma_b);

    soma_a -= a[esq];
    remover(b[esq]);

    if(esq + 1 >= n) {
      passei = true;
    }
    esq = (esq + 1) % n;
    dir = (dir + 1) % n;

    if(passei_dois) break;

    soma_a += a[dir];
    inserir(b[dir]);
  }

  cout << ans << endl;

  return 0;
}

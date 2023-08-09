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

ll N, L;

class Atendente {
  public:
    ll id;
    ll minuto_final;
    ll quantidade_ligacoes;

  Atendente(){};
  Atendente(ll i, ll min_final = 0, ll qtd_ligacoes = 0) {
    id = i;
    minuto_final = min_final;
    quantidade_ligacoes = qtd_ligacoes;
  }

  Atendente atender(ll min_final) {
    return *new Atendente(id, minuto_final + min_final, quantidade_ligacoes + 1);
  }
};

class Compare {
  public:
    bool operator()(const Atendente& a, const Atendente& b) const {
      if(a.minuto_final == b.minuto_final) return a.id > b.id;
      return a.minuto_final > b.minuto_final;
    }
};

priority_queue<Atendente, vector<Atendente>, Compare> atendentes;
queue<ll> ligacoes;

bool cmp(const Atendente& a, const Atendente& b) {
  return a.id < b.id;
}

int main()
{
  speed;
  cin >> N >> L;

  for(ll i = 1; i <= N; i++) {
    atendentes.push(*new Atendente(i));
  }

  for(ll i = 0; i < L; i++) {
    ll duracao_ligacao; cin >> duracao_ligacao;
    ligacoes.push(duracao_ligacao);
  }

  while(!ligacoes.empty()) {
    Atendente prox = atendentes.top();
    atendentes.pop();

    atendentes.push(prox.atender(ligacoes.front()));
    ligacoes.pop();
  }

  vector<Atendente> org;
  while(!atendentes.empty()) {
    org.pb(atendentes.top());
    atendentes.pop();
  }

  sort(all(org), cmp);

  for(auto a : org) {
    cout << a.id << " " << a.quantidade_ligacoes << endl;
  }

  return 0;
}

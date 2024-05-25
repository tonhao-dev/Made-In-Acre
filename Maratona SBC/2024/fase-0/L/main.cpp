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

int main() {
    speed;
    int n;
    cin >> n;

    vector<string> quartos(n);
    map<string, int> nome_idade;
    map<int, string> idade_nome;

    for(auto &i : quartos) cin >> i;
    for(int i = 0; i < n; i++) {
        string c; cin >> c;
        nome_idade[c] = i;
        idade_nome[i] = c;
    }

    int flag = 0;
    for(int i = 0; i < n; i++) {
        auto atual = quartos[i];

        auto nova = *idade_nome.begin();
        if(flag) cout << " ";
        flag = 1;
        cout << nova.second;

        auto id = nome_idade[atual];
        idade_nome.erase(idade_nome.find(id));
    }

    cout << endl;

    return 0;
}

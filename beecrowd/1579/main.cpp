// https://www.beecrowd.com.br/judge/pt/problems/view/1579
// busca-binária
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

bool consegue(vll &paines, ll caminhoes, ll limit_carga)
{
    ll carga_atual = 0;
    for (ll i = 0; i < sz(paines); i++)
    {
        if (paines[i] > limit_carga)
        {
            return false;
        }
        if (caminhoes < 0)
        {
            return false;
        }

        if ((carga_atual + paines[i]) > limit_carga)
        {
            caminhoes--;
            carga_atual = paines[i];
            continue;
        }

        carga_atual += paines[i];
    }

    return caminhoes >= 1;
}

ll min_carga(vll &paines, ll caminhoes)
{
    ll l = 0, r = 1e5, minimo = 0;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (consegue(paines, caminhoes, mid))
        {
            r = mid;
            minimo = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return minimo;
}

int main()
{
    speed;
    ll qtd;
    cin >> qtd;

    while (qtd--)
    {
        ll n_paineis, total_caminhoes, frete;
        cin >> n_paineis >> total_caminhoes >> frete;

        vll paines(n_paineis);
        for (ll i = 0; i < n_paineis; i++)
            cin >> paines[i];

        ll carga = min_carga(paines, total_caminhoes);

        cout << carga << " $" << (carga * total_caminhoes) * frete << endl;
    }

    return 0;
}

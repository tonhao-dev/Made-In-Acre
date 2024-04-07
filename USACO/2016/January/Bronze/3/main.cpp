/**
 * USACO 2016 January Contest, Bronze
 * Problem 3. Mowing the Field
 * Adhoc, Simulação
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG) cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)                           \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define dbmap(map)                          \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(int argc, char** argv) {
    SPEED;

    setIO("mowing");
    int n; cin >> n;
    vector<char> dir(n);
    vector<int> tempo(n);

    for(int i = 0; i < n; i++) {
        cin >> dir[i] >> tempo[i];
    }

    map<char, pii> direcoes = {
        {'N', {-1, 0}},
        {'S', {1, 0}},
        {'W', {0, -1}},
        {'E', {0, 1}},
    };

    map<pii, int> visitado;

    pii posi = {0, 0};
    int tempo_atual = 1;
    int ans = INF;
    int flag = 0;
    set<int> posicoes;
    for(int i = 0; i < n; i++) {
        int rep = tempo[i];

        while(rep--) {
            posi.f = posi.f + direcoes[dir[i]].f;
            posi.s = posi.s + direcoes[dir[i]].s;

            if(visitado.count(posi)) {
                flag = 1;
                ans = min(ans, abs(visitado[posi] - tempo_atual));
            }

            visitado[posi] = tempo_atual;
            tempo_atual++;
        }
    }

    if(flag) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}

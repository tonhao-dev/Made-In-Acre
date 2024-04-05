/**
 * USACO 2018 December Contest, Bronze
 * Problem 2. The Bucket List
 * Adhoc, Simulação
 * Classe, Struct
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

struct Vaca {
    int tempo_inicio;
    int tempo_fim;
    int baldes;

    bool operator < (const Vaca& b) const {
        return (tempo_inicio < b.tempo_inicio);
    }
};

int main(int argc, char** argv) {
    SPEED;

    setIO("blist");

    int n; cin >> n;

    vector<Vaca> vacas(n);

    int max_tempo = 0;
    for(int i = 0; i < n; i++) {
        int s1, t1, b1; cin >> s1 >> t1 >> b1;
        Vaca vaca;
        vaca.tempo_inicio = s1;
        vaca.tempo_fim = t1;
        vaca.baldes = b1;

        vacas[i] = vaca;
        max_tempo = max(t1, max_tempo);
    }

    vector<pii> tempos(max_tempo + 10, {-1, -1});
    for(auto vaca : vacas) {
        tempos[vaca.tempo_inicio] = mp(1, vaca.baldes);
        tempos[vaca.tempo_fim] = mp(0, vaca.baldes);
    }

    int ans = 0;
    int bonus = 0;

    for(int i = 1; i < tempos.size(); i++) {
        if(tempos[i].f == -1) continue;

        if(tempos[i].f == 0) {
            bonus += tempos[i].s;
            continue;
        }

        auto necesarios = tempos[i].s;
        bonus -= necesarios;
        if(bonus < 0) {
            ans += abs(bonus);
            bonus = 0;
        }
    }

    cout << ans << endl;

    return 0;
}

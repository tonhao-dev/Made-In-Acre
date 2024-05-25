/**
 * [Link]
 * [Título da questão]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
#define db(x)  \
    if (DEBUG) \
    cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG)    \
    cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)          \
    {                             \
        cout << #vector << " = "; \
        for (auto &it : vector)   \
            cout << it << " ";    \
        cout << endl;             \
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

void solve()
{
}

int main(int argc, char **argv)
{
    SPEED;

    /**
     * Não esqueça de adicionar o link da questão e o assunto S2
     */

    int e, v, resp = 19;
    cin >> e >> v;

    double tempo = (double)e/v;
    db(tempo);
    int tempoMinutos = tempo*60;
    db(tempoMinutos);
    int horasRs = tempoMinutos / 60;
    db(horasRs);
    int minutosRs = tempoMinutos - (horasRs*60);
    db(resp);
    db(horasRs);
    resp= (resp + horasRs)%24;
    if(resp < 10) {
        cout << "0";
    }
    cout << resp << ":";

    if(minutosRs < 10) {
        cout << "0";
    }

    cout << minutosRs << endl;

    return 0;
}




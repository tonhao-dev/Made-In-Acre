/**
 * https://judge.beecrowd.com/pt/problems/view/1913
 * Ajude o Sr. Barriga
 * Programação Dinâmica
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

struct Cilindro {
    int h;
    int r;
    int cor;
};

bool cmp(Cilindro& a, Cilindro& b) {
    return a.r > b.r;
}

int n;
vector<Cilindro> c;
int memo[1010][1010][5];

bool valido(Cilindro atual, int r, int cor) {
    if (atual.r == r) return false;
    if (atual.cor == 1 && cor == 2) return false;
    if (atual.cor == 2 && cor == 4) return false;
    if (atual.cor == 4 && cor == 3) return false;
    if (atual.cor == 3 && cor == 1) return false;
    return true;
}

int dp(int i, int r, int cor) {
    if (i == n) return 0;

    if (memo[i][r][cor] != -1)
        return memo[i][r][cor];

    auto pegar = -INF;
    if (valido(c[i], r, cor))
        pegar = c[i].h + dp(i + 1, c[i].r, c[i].cor);
    auto passar = dp(i + 1, r, cor);

    return memo[i][r][cor] = max(pegar, passar);
}

int main(int argc, char** argv) {
    SPEED;

    map<string, int> to_cor = {
        {"VERMELHO", 1},
        {"LARANJA", 2},
        {"VERDE", 3},
        {"AZUL", 4},
    };

    while (cin >> n, n) {
        c.clear();
        for (int i = 0; i < n; i++) {
            Cilindro c1;
            string cor;
            cin >> c1.h >> c1.r >> cor;
            c1.cor = to_cor[cor];

            c.push_back(c1);
        }

        sort(all(c), cmp);

        memset(memo, -1, sizeof memo);

        cout << dp(0, 0, 0) << " centimetro(s)" << endl;
    }

    return 0;
}

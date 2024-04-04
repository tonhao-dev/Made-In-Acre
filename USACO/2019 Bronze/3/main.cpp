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

int main(int argc, char** argv) {
    SPEED;

    setIO("traffic");
    int n; cin >> n;

    vector<int> antes = {-INF, INF};
    vector<int> depois = {-INF, INF};

    vector<tuple<string, int, int>> sensores(n);

    for(int i = 0; i < n; i++) {
        string tipo;
        int s1, s2;
        cin >> tipo >> s1 >> s2;

        sensores[i] = make_tuple(tipo, s1, s2);
    }

    for(int i = n - 1; i >= 0; i--) {
        string tipo = get<0>(sensores[i]);
        int range1 = get<1>(sensores[i]), range2 = get<2>(sensores[i]);

        if(tipo == "none") {
            antes[0] = max(range1, antes[0]);
            antes[1] = min(range2, antes[1]);
            continue;
        }

        if(tipo == "on") {
            antes[0] -= range2;
            antes[1] -= range1;
            if(antes[0] < 0) antes[0] = 0;
            continue;
        }

        antes[0] += range1;
        antes[1] += range2;
    }

    for(int i = 0; i < n; i++) {
        string tipo = get<0>(sensores[i]);
        int range1 = get<1>(sensores[i]), range2 = get<2>(sensores[i]);

        if(tipo == "none") {
            depois[0] = max(range1, depois[0]);
            depois[1] = min(range2, depois[1]);
            continue;
        }

        if(tipo == "on") {
            depois[0] += range1;
            depois[1] += range2;
            if(depois[0] < 0) depois[0] = 0;
            continue;
        }

        depois[0] -= range2;
        depois[1] -= range1;
        if(depois[0] < 0) depois[0] = 0;
    }

    cout << antes[0] << " " << antes[1] << endl;
    cout << depois[0] << " " << depois[1] << endl;

    return 0;
}

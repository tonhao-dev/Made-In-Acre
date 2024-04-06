/**
 * USACO 2016 December Contest, Bronze
 * Problem 2. Block Game
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

    setIO("blocks");
    int n; cin >> n;

    vector<int> letras(26, 0);
    for(int i = 0; i < n; i++) {
        vector<int> letras_s1(26, 0);
        vector<int> letras_s2(26, 0);

        string s1, s2, s = "";
        cin >> s1 >> s2;

        for(auto c : s1) {
            letras_s1[c - 'a']++;
        }
        for(auto c : s2) {
            letras_s2[c - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            letras[i] += max(letras_s1[i], letras_s2[i]);
        }
    }

    for(auto l : letras) {
        cout << l << endl;
    }

    return 0;
}

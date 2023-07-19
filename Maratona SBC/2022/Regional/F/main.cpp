/**
 * [Nome da questão]
 * beecrowd | [Número]
 * [Link]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define db(x) cout << #x << ": " << x << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cm(map)                             \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

vector<char> alfabeto{'a', 'b', 'c','d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t','u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);
    ll m, n;
    string ans;

    cin >> m >> n;

    map<string, ll> mapa;
    cin.ignore();
    rep(i, m){
        string palavra;
        int pos;
        getline(cin, palavra);

        for(auto letra: alfabeto) {
            string copia = palavra;
            replace(all(copia), '*', letra);
            mapa[copia]++;
        }
    }

    int bigger = -1;
    for(auto item : mapa) {
        if(item.second > bigger) {
            ans = item.first;
            bigger = item.second;
        }
    }
    cout << ans << " " << bigger <<endl;
    return 0;
}

/**
 * https://vjudge.net/contest/431956#problem/E
 * strings
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
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

int main(int argc, char **argv) {
    SPEED;
    ll tam;
    cin >> tam;
    cin.ignore();
    string words;

    getline(cin, words);

    ll n_qtd=0, z_qtd=0;
    foreach(letra, words) {
        if(letra == 'n') n_qtd++;
        if(letra == 'z') z_qtd++;
    }

    rep(i, n_qtd) {
        cout << 1 << " ";
    }
    rep(i, z_qtd) {
        cout << 0 << " ";
    }
    cout << endl;

    return 0;
}

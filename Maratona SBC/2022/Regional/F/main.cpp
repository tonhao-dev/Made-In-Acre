/**
 * https://codeforces.com/gym/103960/problem/F
 * Map, string, max
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

    ll n, c;
    cin >> n >> c;
    map<string, ll> dict;
    pair<string, ll> resp;

    rep(i, n) {
        string word;
        cin >> word;

        for(char letra = 'a'; letra <= 'z'; letra++) {
            string copia = word;
            replace(all(copia), '*', letra);
            dict[copia]++;
        }
    }

    ll max = -INT_MAX;
    foreach(value, dict) {
        if(value.s > max) {
            resp = value;
            max = value.s;
        }
    }

    cout << resp.f << " " << resp.s << endl;

    return 0;
}

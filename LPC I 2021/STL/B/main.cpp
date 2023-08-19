/**
 * https://vjudge.net/contest/433311#problem/B
 * string, pilha, stack
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
#define MOD 1e9 + 7
#define log(x) cout << x << endl

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    SPEED;
    stack<char> p;
    string texto;
    getline(cin, texto);
    rep(i, texto.size()) {
        if (p.empty()) {
            p.push(texto[i]);
            continue;
        } else if (p.top() == texto[i]) {
            p.pop();
        } else {
            p.push(texto[i]);
        }
    }

    string resp;
    while (!p.empty()) {
        resp += p.top();
        p.pop();
    }

    Rep(i, resp.size() - 1, 0) {
        cout << resp[i];
    }
    log("");

    return 0;
}

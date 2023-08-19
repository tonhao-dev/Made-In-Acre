/**
 * https://vjudge.net/contest/433311#problem/C
 * pilha, notação polonesa, matematica, string, math
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

void mostra_fila(queue<char> &fila) {
    while (!fila.empty()) {
        cout << fila.front();
        fila.pop();
    }
}

void mostra_pilha(stack<char> &pilha) {
    while (pilha.top() != '(') {
        cout << pilha.top();
        pilha.pop();
    }
    pilha.pop();
}

int main(int argc, char **argv) {
    SPEED;
    ll n;
    cin >> n;

    cin.ignore();
    rep(i, n) {
        string exp;
        getline(cin, exp);

        stack<char> p;
        queue<char> q;

        rep(k, exp.size()) {
            if (exp[k] == '(') {
                p.push(exp[k]);
                continue;
            }

            if (exp[k] == ')') {
                mostra_fila(q);
                mostra_pilha(p);

                continue;
            }

            if (isalpha(exp[k])) {
                q.push(exp[k]);
                continue;
            }

            p.push(exp[k]);
        }

        log("");
    }

    return 0;
}

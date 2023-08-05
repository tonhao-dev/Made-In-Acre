/**
 * https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
 * busca binária, binary search
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
#define in(x) cin >> x

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

string busca_binaria(vll& vector, ll search) {
    string resp = "NO";

    ll esquerda = 0, direita = vector.size();
    ll meio;

    while(esquerda < direita) {
        meio = (esquerda + direita) / 2;

        if(vector[meio] == search) {
            resp = "YES";
            break;
        }

        if(vector[meio] > search) {
            direita = meio;
            continue;
        }

        if(vector[meio] < search) {
            esquerda = meio + 1;
            continue;
        }
    }

    return resp;
}

int main(int argc, char **argv) {
    SPEED;
    ll n, k;
    cin >> n >> k;
    vll values(n);
    rep(i, n) in(values[i]);
    rep(i, k) {
        ll search;
        in(search);
        log(busca_binaria(values, search));
    }

    return 0;
}

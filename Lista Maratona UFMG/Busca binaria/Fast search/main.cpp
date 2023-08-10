/**
 * https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
 * busca binaria, ordenacao
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = " << ;              \
        for (auto &it : vector) cout << it << " "; \
        cout << endl;                              \
    }
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

template <typename T>
void read(T &arg) {
    cin >> arg;
}

template <typename T, typename... Args>
void read(T &first, Args &...args) {
    cin >> first;
    read(args...);
}

int main(int argc, char **argv) {
    SPEED;
    ll n;
    read(n);

    vll a(n);
    rep(i, n) read(a[i]);

    sort(all(a));

    ll q;
    read(q);
    rep(i, q) {
        ll l, r;
        read(l, r);

        auto it_l = lower_bound(all(a), l);
        auto it_r = upper_bound(all(a), r);

        if (it_l == a.end() && l < a[0]) it_l = a.begin();

        cout << it_r - it_l << " ";
    }
    log("");

    return 0;
}

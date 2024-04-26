#include <bits/stdc++.h>

using namespace std;

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vstr;
typedef vector<vll> vvll;

#define endl "\n"
#define print_vector(vector) \
    for (auto x : vector)    \
        cout << x << " ";    \
    cout << endl
#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    speed;

    map<char, pii> dict = {
        {'C', {1, 0}},
        {'E', {0, -1}},
        {'B', {-1, 0}},
        {'D', {0, 1}},
    };

    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    vector<pii> cobra(n);
    map<pii, bool> contida;
    for (auto &i : cobra) {
        cin >> i.f >> i.s;
        contida[{i.f, i.s}] = true;
    }

    int q;
    cin >> q;

    bool morreu = false;
    while (q--) {
        char mov;
        cin >> mov;

        if (morreu) continue;

        auto ponta = cobra.front();
        auto coord = dict[mov];

        auto nova = mp(ponta.f + coord.f, ponta.s + coord.s);

        if (nova.f < 0 || nova.f > a || nova.s < 0 || nova.s >= b) {
            morreu = true;
            cout << "A cobra morreu" << endl;
            continue;
        }

        if (contida[nova] && cobra.back().f != nova.f && cobra.back().s != nova.s) {
            morreu = true;
            cout << "A cobra morreu" << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            auto velha = cobra[i];

            contida[velha] = 0;
            contida[nova] = 1;

            cobra[i] = nova;
            nova = velha;
        }
    }

    if (!morreu) {
        cout << cobra.front().f << " " << cobra.front().s << endl;
        cout << cobra.back().f << " " << cobra.back().s << endl;
    }

    return 0;
}

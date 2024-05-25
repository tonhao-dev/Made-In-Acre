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

bool isPrime(ll n) {
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

pair<ll, ll> testar(ll n, ll arg) {
    // cout << "testar" << endl;

    ll a = n / 2;
    ll b = a / arg;
    ll c = b * arg;

    ll d = abs(n - c);

    // cout << "fim-testar" << endl;
    return {c, d};
}

int main() {
    speed;

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        if (n <= 3) {
            cout << -1 << endl;
            continue;
        }

        pair<ll, ll> resp = {1, n - 1};


        for (ll i = n/2; i > 1 ; i--) {
            pair<ll, ll> atual = testar(n, i);

            if(atual.f %2 == 0 && atual.s%2== 0) continue;
            if(atual.f %2 !=0 && atual.s%2!=0) continue;

            if(atual.f %2 !=0 && isPrime(atual.f)) continue;
            if(atual.s %2 !=0 && isPrime(atual.s)) continue;

            resp = atual;
            break;
        }

        cout << resp.f << " " << resp.s << endl;
    }

    return 0;
}

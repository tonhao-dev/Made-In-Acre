#include <bits/stdc++.h>

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007

using namespace std;
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
#define endl "\n"
#define f first
#define s second

ull N, K;
vector<pair<ull, ull>> pessoas(1e5 + 1);

bool consegue(ull tempo)
{
    ull total_views = 0;
    for (ull i = 0; i < N; i++)
    {
        if (pessoas[i].f > tempo)
            continue;
        total_views++;

        auto resto = tempo - pessoas[i].f;
        total_views += (resto / pessoas[i].s);
    }

    return total_views >= K;
}

int main()
{
    speed;
    cin >> N >> K;

    for (ull i = 0; i < N; i++)
        cin >> pessoas[i].f >> pessoas[i].s;

    ull l = 0, r = 2 * 1e18, ans;
    while (l < r)
    {
        ull mid = (l + r) / 2;

        if (consegue(mid))
        {
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

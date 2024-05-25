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

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    speed;
    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        pair<int, int> res = {-1, -1};
        int diff = INF;
        for (int x = 1; x <= n; x++)
        {
            for (int y = x; y <= n; y++)
            {
                if (x + y == n && abs(x - y) <= diff && !isPrime(x) && !isPrime(y))
                {
                    res = {x, y};
                    diff = abs(x - y);
                }
            }
        }
        if(res.first == -1) {
            cout << res.first << endl;
        } else {
            cout << res.first << " " << res.second << endl;
        }
    }

    return 0;
}

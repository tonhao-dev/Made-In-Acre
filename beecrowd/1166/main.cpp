/**
 * Torre de Hanoi, Novamente! - https://www.beecrowd.com.br/judge/pt/problems/view/1166
 * Paradigmas, backtracking, brute
 */

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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int t, n;
int tot;
int arr[55];

void backtrack(int cur, int pos) {
    if (pos == n)
        return;
    if (arr[pos] == 0) {
        tot++;
        arr[pos] = cur;
        return backtrack(cur + 1, pos);
    }

    for (int i = 0; i <= pos; i++)
    {
        int r = sqrt(arr[i] + cur);
        if (r * r == arr[i] + cur) {
            arr[i] = cur;
            tot++;
            return backtrack(cur + 1, pos);
        }
    }

    backtrack(cur, pos + 1);
}

int main()
{
    speed;
    cin >> t;

    while (t--) {
        tot = 0;
        cin >> n;
        memset(arr, 0, sizeof(arr));
        backtrack(1, 0);
        cout << tot << endl;
    }
}

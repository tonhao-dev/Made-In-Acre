#include <bits/stdc++.h>

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define lll long long int
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

int main() {
    speed;

    while (true) {
        ll h, qtd;
        cin >> h >> qtd;

        if (h == 0 && qtd == 0)
            break;

        vector<ll> blocos(qtd, 0);
        for (ll i = 0; i < qtd; i++) {
            cin >> blocos[i];
        }

        ll ans = h - blocos[0];
        for (ll i = 1; i < qtd; i++) {
            if (blocos[i] >= blocos[i - 1]) {
                continue;
            }

            ans += abs(blocos[i] - blocos[i - 1]);
        }

        cout << ans << endl;
    }

    return 0;
}

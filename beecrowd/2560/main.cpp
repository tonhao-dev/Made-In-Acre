#include <bits/stdc++.h>

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define all(x) begin(x), end(x)
#define lll long long int
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

int main() {
    speed;
    ll N, B;
    while (cin >> N >> B) {
        vector<ll> notas(N);
        multiset<ll> fila_notas;

        ll sum = 0;
        ll ans = 0;

        for (ll i = 0; i < N; i++) {
            cin >> notas[i];
            if (fila_notas.size() <= B) {
                fila_notas.insert(notas[i]);
                sum += notas[i];
            }

            if (fila_notas.size() != B)
                continue;

            ll total_bateria = (sum - *fila_notas.begin()) - *fila_notas.rbegin();
            ans += total_bateria;

            ll numero_para_remover = notas[i + 1 - B];
            sum -= numero_para_remover;

            fila_notas.erase(fila_notas.find(numero_para_remover));
        }

        cout << ans << endl;
    }

    return 0;
}

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

#define lll long long int
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

void printIndex(ll &index) {
    if (index == -1) {
        cout << '*';
        return;
    }
    cout << index;
}

int main() {
    speed;

    while (true) {
        ll qtd_combatentes, baixas;
        cin >> qtd_combatentes >> baixas;

        if (qtd_combatentes == 0 && baixas == 0)
            break;

        unordered_map<ll, pll> combatentes;
        for (ll i = 1; i <= qtd_combatentes; i++) {
            ll end = i + 1 > qtd_combatentes ? -1 : i + 1;
            ll begin = i - 1 == 0 ? -1 : i - 1;
            combatentes[i] = {begin, end};
        }

        while (baixas--) {
            ll index_inicio, index_final;
            cin >> index_inicio >> index_final;

            pll primeiro_morto = combatentes[index_inicio];
            pll ultimo_morto = combatentes[index_final];

            printIndex(primeiro_morto.first);
            cout << " ";
            printIndex(ultimo_morto.second);
            cout << endl;

            if (primeiro_morto.first != -1) {
                combatentes[primeiro_morto.first].s = ultimo_morto.s != -1 ? ultimo_morto.s : -1;
            }

            if (ultimo_morto.s != -1) {
                combatentes[ultimo_morto.s].f = primeiro_morto.f != -1 ? primeiro_morto.f : -1;
            }
        }
        cout << "-" << endl;
    }

    return 0;
}

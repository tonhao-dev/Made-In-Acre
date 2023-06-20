#include <bits/stdc++.h>
using namespace std;

#define db(message, x) cout << message << ": " << x << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    while (true) {
        ll g, p;
        cin >> g >> p;
        if (g == 0 && p == 0) break;

        vector<vector<ll>> grandprix(g);

        rep(i, 0, g) {
            rep(j, 0, p) {
                ll posicao;
                cin >> posicao;
                grandprix[i].push_back(posicao);
            }
        }

        ll s;
        cin >> s;
        rep(i, 0, s) {
            ll size;
            cin >> size;
            vector<ll> tabela(p);

            rep(j, 0, size) cin >> tabela[j];

            vector<pii> ranking(p);
            rep(j, 0, p) ranking[j] = make_pair(0, j);

            for (auto corrida : grandprix) {
                rep(k, 0, p) {
                    ranking[k] = make_pair(ranking[k].first + tabela[corrida[k] - 1] * -1, ranking[k].second);
                }
            }

            sort(all(ranking));

            auto winner_points = ranking.begin()->first;
            vi saida;
            for (auto piloto : ranking) {
                if (piloto.first == winner_points) {
                    saida.push_back(piloto.second + 1);
                } else
                    break;
            }
            rep(j, 0, sz(saida)) {
                if (j == sz(saida) - 1)
                    cout << saida[j] << endl;
                else
                    cout << saida[j] << " ";
            }
        }
    }

    return 0;
}

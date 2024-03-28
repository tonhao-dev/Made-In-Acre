/**
 * https://judge.beecrowd.com/pt/problems/view/1907
 * DFS, grafo, grafo disconexo, grafo nao conexo
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG false
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define print_map(map)                      \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto&(a) : (b))
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

ll linhas, colunas;

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

void dfs(ll i, ll j, vector<string>& imagem, vector<vector<bool>>& visitado) {
    stack<pll> pilha;

    visitado[i][j] = true;
    pilha.push({i, j});

    while (!pilha.empty()) {
        pll current = pilha.top();

        pilha.pop();

        if (current.f + 1 < linhas && imagem[current.f + 1][current.s] == '.' && visitado[current.f + 1][current.s] == false) {
            pilha.push({current.f + 1, current.s});
            visitado[current.f + 1][current.s] = true;
        }
        if (current.f - 1 >= 0 && imagem[current.f - 1][current.s] == '.' && visitado[current.f - 1][current.s] == false) {
            pilha.push({current.f - 1, current.s});
            visitado[current.f - 1][current.s] = true;
        }
        if (current.s + 1 < colunas && imagem[current.f][current.s + 1] == '.' && visitado[current.f][current.s + 1] == false) {
            pilha.push({current.f, current.s + 1});
            visitado[current.f][current.s + 1] = true;
        }
        if (current.s - 1 >= 0 && imagem[current.f][current.s - 1] == '.' && visitado[current.f][current.s - 1] == false) {
            pilha.push({current.f, current.s - 1});
            visitado[current.f][current.s - 1] = true;
        }
    }
}

ll dfs_disconnected(vector<string>& imagem) {
    vector<vector<bool>> visitado(linhas, vector<bool>(colunas, false));

    ll resp = 0;
    rep(i, linhas) {
        rep(j, colunas) {
            if (imagem[i][j] == 'o' || visitado[i][j]) continue;

            resp++;
            dfs(i, j, imagem, visitado);
        }
    }

    return resp;
}

int main(int argc, char** argv) {
    SPEED;

    read(linhas, colunas);

    vector<string> imagem(linhas);

    rep(i, linhas) {
        read(imagem[i]);
    }

    cout << dfs_disconnected(imagem) << endl;

    return 0;
}

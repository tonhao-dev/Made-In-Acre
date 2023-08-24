#include <bits/stdc++.h>

#include <array>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

template <typename T = int>
vector<T> create(size_t n) { return vector<T>(n); }
template <typename T, typename... Args>
auto create(size_t n, Args... args) { return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;

int main() {
    // desincronizar o C++ do C e tornar o codigo C++ mais rapido
    ios::sync_with_stdio(false);
    // Não espera que o CIN seja executado para poder fazer o COUT
    // Como a ordem da entrada e saida não importam, pois a entrada é automatizada
    // Faz sentido usar essa instrução
    cin.tie(nullptr);

    int numEnderecos, numListas;
    cin >> numEnderecos >> numListas;
    vector<vector<int>> grafo(numEnderecos);
    vector<int> deg(numEnderecos);

    for (int i = 0; i < numListas; i++) {
        int tamanhoLista;
        cin >> tamanhoLista;
        for (int j = 0; j < tamanhoLista; j++) {
            int u;
            cin >> u;
            u--;
            grafo[i].push_back(u);

            /**
             * Usamos essa estrutura para saber qual o grau de cada no
             * do grafo, dessa maneira conseguimos navegar sempre para o próximo no
             * que possui grau de entrada igual a 0
             */
            deg[u]++;
        }
    }

    queue<int> fila;
    for (int i = 0; i < numListas; i++)
        if (deg[i] == 0) {
            fila.push(i);
        }

    // Ordenação topologica
    /*
     * O seen(n) entra como uma estrategia para contar quais
     * clientes receberam email, não podemos fazer uma contagem
     * de quais valores entre L e N são diferentes de 0 pois quanto
     * aplicamos MOD 10ˆ9+7 pode ser que o valor resultante seja 0
     */
    vector<int> tot_emails(numEnderecos), seen(numEnderecos);
    // Sabemos que enviamos um email e visitamos a lista 1
    tot_emails[0] = 1;
    seen[0] = 1;
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        for (int v : grafo[u]) {
            tot_emails[v] += tot_emails[u];
            // Sempre tomando cuidado para tot_emails não passar de MOD
            tot_emails[v] %= MOD;
            /*
             * Se seen[u] == 1 e seen[v] == 1 entao seen[v] vira 2
             *  e ele é atualizado para min(seen[v], 1)
             * Voltando para o valor 1 novamente
             * Esse controle é pra saber quais clientes receberam email na segunda rodada
             */
            seen[v] += seen[u];
            seen[v] = min(seen[v], 1);
            /** Se expandimos um vertice, reduzimos o grau dele
             * dessa maneira em algum momento ele terá grau 0 e entrará
             * na nossa fila para poder ser expandido
             */
            --deg[v];
            if (deg[v] == 0) {
                fila.push(v);
            }
        }
    }
    // ------------ //
    int antes_otimizacao = 0, depois_otimizacao = 0;
    for (int i = numListas; i < numEnderecos; i++) {
        antes_otimizacao += tot_emails[i];
        antes_otimizacao %= MOD;
        depois_otimizacao += seen[i];
    }
    cout << antes_otimizacao << ' ' << depois_otimizacao << '\n';
    return 0;
}

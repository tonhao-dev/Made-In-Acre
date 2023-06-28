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

    ll n, k;
    cin >> n >> k;

    ll resp;
    ll fator = 2 * n + 1;  // A cada iteração devo verificar se o i^2 é divisivel por esse fator
    ll maxn = 2 * n;
    /* Até onde eu entendi a próxima linha é necessária porque no problema temos a seguinte restrição
     * 1<= K <=(2N)^2, o que significa que o Bob (quem faz a primeira jogada) pode escolher o maior valor
     * que foi desenhado na lousa (2*N^2), desse modo não podemos inicializar nosso maxn com o valor de n*2,
     * logo, somos obrigados a iniciar nosso maxn com o valor de 2*n-1, e ir fazendo as operações com os quadrados
     * perfeitos a partir dai. Entretanto, se bob (K) não escolher o maior valor (2*N^2) então podemos
     * começar nosso maxn com o valor de 2*N.
     * Exemplo:
     * N = 2
     * Valores = 1^2, 2^2, 3^2, 4^2
     * Bob escolhe K = 8
     * Logo, maxn não pode ser 4, pois 4^2 já foi escolhido, então, maxn decrementa 1, ficando
     * MaxN = 3
     */
    maxn -= pow(2 * n, 2) == k ? 1 : 0;
    for (ll i = maxn; i >= 1; --i) {
        if (abs((ll)pow(i, 2) - k) % fator == 0) {
            // db("i", i);
            resp = pow(i, 2);
            break;
        }
    }

    cout << resp << "\n";

    return 0;
}

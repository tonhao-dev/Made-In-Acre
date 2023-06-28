/**
 * Comparação de Substring
 * beecrowd | 1237
 * https://www.beecrowd.com.br/judge/pt/problems/view/1237
 * LCS, MSC
 */

#include <bits/stdc++.h>

using namespace std;

#define CIMA 'N'
#define DIREITA 'E'
#define BAIXO 'S'
#define ESQUERDA 'W'

#define db(message, x) cout << message << ": " << x << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cm(map)                             \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int lcs(string& X, string& Y, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                          lcs(X, Y, m - 1, n, dp));
}

string pathCrianca(vector<string>& grade, map<char, pair<ll, ll>>& mascara) {
    ll n, x, y;
    string direcoes;
    cin >> n >> x >> y;

    string caminho;

    x--;
    y--;

    // Caso não hajam instruções a serem lidas então devolvemos apenas
    // A letra na qual a criança está
    if (n == 0) {
        caminho += grade[x][y];
        return caminho;
    };

    cin.ignore();  // quando temos que ler uma string apos ter lido um int
    getline(cin, direcoes);

    rep(i, 0, n + 1) {
        caminho += grade[x][y];
        x += mascara[direcoes[i]].first;
        y += mascara[direcoes[i]].second;
    }

    return caminho;
}

int main(int argc, char** argv) {
    cin.tie(0)->sync_with_stdio(0);

    map<char, pair<ll, ll>> mascara = {
        {CIMA, {-1, 0}},
        {DIREITA, {0, 1}},
        {BAIXO, {1, 0}},
        {ESQUERDA, {0, -1}}};

    ll t;
    cin >> t;
    rep(teste, 1, t + 1) {
        ll w, h;
        cin >> w >> h;
        cin.ignore();  // quando temos que ler uma string apos ter lido um int
        vector<string> grade(w);
        rep(j, 0, w) {
            string linha;
            getline(cin, linha);
            grade[j] = linha;
        }

        string s1 = pathCrianca(grade, mascara);
        string s2 = pathCrianca(grade, mascara);

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        ll diff = lcs(s1, s2, s1.size(), s2.size(), dp);

        cout << "Case " << teste << ": " << s1.size() - diff << " " << s2.size() - diff << endl;
    }

    return 0;
}

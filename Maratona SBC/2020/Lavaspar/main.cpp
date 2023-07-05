/**
 * Lavaspar
 * codeforces | 102861
 * https://codeforces.com/gym/102861/problem/L
 * Matriz, anagrama, string, brute force
 */

#include <bits/stdc++.h>

using namespace std;

#define CIMA 'W'
#define CIMA_DIREITA 'E'
#define DIREITA 'D'
#define DIREITA_BAIXO 'C'
#define BAIXO 'X'
#define BAIXO_ESQUERDA 'Z'
#define ESQUERDA 'A'
#define ESQUERDA_CIMA 'Q'

#define endl "\n"
#define db(x) cout << #x << ": " << x << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cvv(matrix)            \
    for (auto vector : matrix) \
        for (auto x : vector)  \
            cout << x << " ";  \
    cout << endl
#define cm(map)                            \
    for (auto e : map)                     \
        cout                               \
            << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

string pega_anagrama(vector<string> &grid, ll i, ll j, pair<char, pair<ll, ll>> direcao, ll size) {
    string anagrama;
    while (grid[i][j] != '#' && anagrama.size() < size) {
        anagrama += grid[i][j];
        i += direcao.s.f;
        j += direcao.s.s;
    }
    return anagrama;
}

void preenche_grid(vector<vector<ll>> &grid, ll i, ll j, pair<char, pair<ll, ll>> direcao, ll size) {
    ll preenchidas = 0;
    while (preenchidas < size) {
        grid[i][j] = 1;
        i += direcao.s.f;
        j += direcao.s.s;
        preenchidas++;
    }
}

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(0);

    map<char, pair<ll, ll>> mascara = {
        {CIMA, {-1, 0}},
        {CIMA_DIREITA, {-1, 1}},
        {DIREITA, {0, 1}},
        {DIREITA_BAIXO, {1, 1}},
        {BAIXO, {1, 0}},
        {BAIXO_ESQUERDA, {1, -1}},
        {ESQUERDA, {0, -1}},
        {ESQUERDA_CIMA, {-1, -1}}};

    ll rows, columns;
    cin >> rows >> columns;
    cin.ignore();

    vector<string> grid(rows + 2);
    grid[0] = string(columns + 2, '#');
    grid[rows + 1] = string(columns + 2, '#');

    FOR(i, 1, rows + 1) {
        string row;
        getline(cin, row);
        grid[i] = '#' + row + '#';
    }

    ll words;
    cin >> words;
    cin.ignore();

    vector<vector<ll>> grid_final(rows + 2, vector<ll>(columns + 2));

    rep(i, words) {
        string word;
        getline(cin, word);
        sort(all(word));

        vector<vector<ll>> grid_word(rows + 2, vector<ll>(columns + 2));

        FOR(linha, 1, rows + 1) {
            FOR(coluna, 1, columns + 1) {
                foreach (direcao, mascara) {
                    string anagrama = pega_anagrama(grid, linha, coluna, direcao, word.size());
                    sort(all(anagrama));

                    if (anagrama != word) continue;

                    preenche_grid(grid_word, linha, coluna, direcao, word.size());
                }
            }
        }

        rep(linha, rows + 1) {
            rep(coluna, columns + 1) {
                grid_final[linha][coluna] += grid_word[linha][coluna];
            }
        }
    }

    ll resp = 0;
    foreach (vector, grid_final) {
        foreach (cell, vector) {
            if (cell >= 2) resp++;
        }
    }

    cout << resp << endl;

    return 0;
}

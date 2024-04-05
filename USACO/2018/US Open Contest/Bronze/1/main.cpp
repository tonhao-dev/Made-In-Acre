/**
 * USACO 2018 US Open Contest, Bronze
 * Problem 1. Team Tic Tac Toe
 * Adhoc, Simulação
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG) cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)                           \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define dbmap(map)                          \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

string set_to_string(set<char>& s) {
    string res;
    for(auto c : s) {
        res.pb(c);
    }
    return res;
}

int main(int argc, char** argv) {
    SPEED;

    setIO("tttt");

    int n = 3;
    vector<string> board(n);
    for(auto &i : board) cin >> i;

    set<string> ind, dupla;

    // coluna
    for(int j = 0; j < n; j++) {
        set<char> vacas;

        for(int i = 0; i < n; i++) {
            vacas.insert(board[i][j]);
        }

        if(vacas.size() == 1) ind.insert(set_to_string(vacas));
        if(vacas.size() == 2) dupla.insert(set_to_string(vacas));
    }

    // linha
    for(int i = 0; i < n; i++) {
        set<char> vacas;
        for(int j = 0; j < n; j++) {
            vacas.insert(board[i][j]);
        }

        if(vacas.size() == 1) ind.insert(set_to_string(vacas));
        if(vacas.size() == 2) dupla.insert(set_to_string(vacas));
    }

    // diagonal
    int i = 0, j = 0;
    set<char> vacas;
    while(i < n) {
        vacas.insert(board[i][j]);
        i++; j++;
    }
    if(vacas.size() == 1) ind.insert(set_to_string(vacas));
    if(vacas.size() == 2) dupla.insert(set_to_string(vacas));
    vacas.clear();

    i = 0;
    j = n - 1;
    while(i < n && j >= 0) {
        vacas.insert(board[i][j]);
        i++; j--;
    }
    if(vacas.size() == 1) ind.insert(set_to_string(vacas));
    if(vacas.size() == 2) dupla.insert(set_to_string(vacas));

    cout << ind.size() << endl;
    cout << dupla.size() << endl;


    return 0;
}

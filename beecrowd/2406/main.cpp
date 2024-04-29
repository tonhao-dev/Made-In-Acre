/**
 * https://judge.beecrowd.com/pt/problems/view/2406
 * Expressões
 * STL, stack
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

void solve() {
    string exp;
    cin >> exp;

    stack<char> pilha;
    bool bemDefinida = true;

    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            pilha.push(exp[i]);
            continue;
        }

        if (pilha.empty()) {
            bemDefinida = false;
            break;
        }

        if (exp[i] == ')' && pilha.top() != '(') {
            bemDefinida = false;
            break;
        }

        if (exp[i] == ']' && pilha.top() != '[') {
            bemDefinida = false;
            break;
        }

        if (exp[i] == '}' && pilha.top() != '{') {
            bemDefinida = false;
            break;
        }

        pilha.pop();
    }

    if (!pilha.empty()) bemDefinida = false;

    cout << (bemDefinida ? "S" : "N") << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}

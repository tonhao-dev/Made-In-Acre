#include <bits/stdc++.h>

using namespace std;

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vstr;
typedef vector<vll> vvll;

#define endl "\n"
#define print_vector(vector) \
  for (auto x : vector)      \
    cout << x << " ";        \
  cout << endl
#define db(x) cout << #x << ": " << x << endl
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, M, K, L;

vector<pair<int, int>> pegar_movimentos(int K, int L) {
    vector<pair<int, int>> moves = {
        {K, L}, {K, -L}, {-K, L}, {-K, -L},
        {L, K}, {L, -K}, {-L, K}, {-L, -K}
    };
    return moves;
}

int valido(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    speed;
    cin >> N >> M;
    cin >> K >> L;
    K--;
    L--;

    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    vector<pair<int, int>> moves = pegar_movimentos(K, L);

    int res = -1;
    pair<int, int> coord;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] != '.') continue;

            int total = 0;
            for(auto mov : moves) {
                int x = i + mov.f;
                int y = j + mov.s;

                if(!valido(x, y)) continue;

                if(board[x][y] == '*') total++;
            }

            if(total > res) {
                res = total;
                coord = {i + 1, j + 1};
            }
        }
    }

    cout << coord.f << " " << coord.s << endl;

    return 0;
}

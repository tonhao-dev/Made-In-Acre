/**
 * [Link] https://www.beecrowd.com.br/judge/pt/problems/view/1337
 * [Assuntos] AD-HOC
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
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

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

int main(int argc, char** argv) {
    SPEED;

    int a,b,c;

    while(cin >> a >> b >> c && a != 0) {
        set<int> numbers;
        vector<int> resp;
        numbers.insert(a);
        numbers.insert(b);
        numbers.insert(c);

        if(numbers.size() == 3){
            cout << "1 1 2" << endl;
            continue;
        }

        if(numbers.size() == 2) {
            int alone;
            int rep;

            if(a == b){
                alone = c;
                rep = a;
            } else if(a == c) {
                alone = b;
                rep = a;
            } else if (b == c) {
                alone = a;
                rep = b;
            }

            if(rep == 13 && alone == 12){
                cout << "1 1 1" << endl;
                continue;
            } else if(alone == 13) {
                resp.push_back(rep + 1);
                resp.push_back(rep + 1);
                resp.push_back(1);
            } else {
                if(alone + 1 == rep) {
                    alone++;
                }
                resp.push_back(rep);
                resp.push_back(rep);
                resp.push_back(alone + 1);
            }
                sort(resp.begin(), resp.end());
                cout << resp[0] << " " << resp[1] << " " << resp[2] << endl;

            continue;
        }

        if(a == 13)
            cout << "*" << endl;
        else
            cout << a + 1 << " " << a + 1 << " " << a + 1 << endl;
    }

    return 0;
}

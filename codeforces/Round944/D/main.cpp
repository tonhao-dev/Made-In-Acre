/**
 * [Link]
 * [Título da questão]
 * [Assuntos]
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
    string S;
    cin >> S;

    int ans = 0;
    bool zeroSequence = false, oneSequence = false;
    bool contou = false;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '1' && !zeroSequence) {
            continue;
        }

        if (S[i] == '0' && !zeroSequence) {
            zeroSequence = true;
            S[i] = '#';
            contou = true;
        }

        if (S[i] == '0' && zeroSequence && !oneSequence) {
            S[i] = '#';
            contou = true;
            continue;
        }

        if (S[i] == '1' && zeroSequence && oneSequence) {
            S[i] = '#';
            contou = true;
            continue;
        }

        if (S[i] == '1' && zeroSequence && !oneSequence) {
            S[i] = '#';
            contou = true;
            oneSequence = true;
        }

        if (S[i] == '0' && oneSequence) {
            contou = true;
            break;
        }
    }

    ans += contou;

    zeroSequence = oneSequence = false;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '#' && (zeroSequence || oneSequence)) {
            zeroSequence = false;
            oneSequence = false;
            continue;
        }

        if (S[i] == '0' && !zeroSequence) {
            zeroSequence = true;
            oneSequence = false;
            ans++;
            continue;
        }

        if (S[i] == '0' && zeroSequence) {
            continue;
        }

        if (S[i] == '1' && !oneSequence) {
            zeroSequence = false;
            oneSequence = true;
            ans++;
            continue;
        }

        if (S[i] == '1' && oneSequence) {
            continue;
        }
    }

    cout << ans << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}

/**
 * Decifra - https://www.beecrowd.com.br/judge/pt/problems/view/2464
 * Adhoc, string
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define SPEED                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define db(x) cout << #x << ": " << x << endl
#define MOD 1e9 + 7
#define FOR(i, a, b) for (ll i = a; i < (b); i++)
#define rep (i, n) FOR(i, 0, n)
#define Rep (i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define log(x) cout << x << endl
#define endl "\n"

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

int main() {
    SPEED;

    map<char, char> decodeKey;
    string decondeString;
    string encoded;
    string ans;

    cin >> decondeString;
    cin >> encoded;

    for (auto letter : encoded) {
        cout << decondeString[letter - 'a'];
    }
    cout << endl;

    return 0;
}

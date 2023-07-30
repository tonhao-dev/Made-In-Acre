/**
 * [Link]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define cv(vector)        \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl
#define cm(map)                             \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9+7
#define log(x) cout << x << endl

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv) {
    SPEED;
    ll commands; cin >> commands;
    list<ll> nums;

    cin.ignore();
    bool isReversed = false;
    rep(i, commands) {
        string command;
        cin >> command;

        if(command == "toFront") {
            ll value; cin >> value;
            isReversed ? nums.push_back(value) : nums.push_front(value);
            continue;
        }

        if(command == "front") {
            if(nums.size() == 0) {
                log("No job for Ada?");
                continue;
            }

            if (isReversed) {
                log(nums.back());
                nums.pop_back();
                continue;
            }

            log(nums.front());
            nums.pop_front();
            continue;
        }

        if(command == "back") {
            if(nums.size() == 0) {
                log("No job for Ada?");
                continue;
            }

            if (isReversed) {
                log(nums.front());
                nums.pop_front();
                continue;
            }

            log(nums.back());
            nums.pop_back();
            continue;
        }

        if(command == "reverse") {
            isReversed = !isReversed;
            continue;
        }

        if(command == "push_back") {
            ll value; cin >> value;
            isReversed ? nums.push_front(value) : nums.push_back(value);
            continue;
        }
    }

    return 0;
}

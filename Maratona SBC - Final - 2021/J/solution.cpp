#include <array>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T = int>
vector<T> create(size_t n) { return vector<T>(n); }
template <typename T, typename... Args>
auto create(size_t n, Args... args) { return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();

using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll W, H;
    cin >> W >> H;
    int n;
    cin >> n;
    vector<pair<ll, ll>> points;
    auto is_border = [&](ll x, ll y) {
        return x == 0 || y == 0 || x == W || y == H;
    };
    auto to_border_num = [&](ll x, ll y) -> ll {
        if (x == 0) {
            // (0, 0) -> (0, H)
            return y;
        }
        if (y == H) {
            // (0, H) -> (W, H)
            return H + x;
        }
        if (x == W) {
            // (W, H) -> (W, 0)
            return H + W + (H - y);
        }
        if (y == 0) {
            // (W, 0) -> (0, 0)
            return H + W + H + (W - x);
        }
    };
    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (is_border(x1, y1) && is_border(x2, y2)) {
            ll a = to_border_num(x1, y1);
            ll b = to_border_num(x2, y2);
            if (a > b)
                swap(a, b);
            points.push_back({a, i});
            points.push_back({b, i});
        }
    }
    sort(points.begin(), points.end());
    stack<int> stk;
    for (auto [_, i] : points) {
        if (!stk.empty() && stk.top() == i) {
            stk.pop();
        } else {
            stk.push(i);
        }
    }
    if (stk.empty()) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    return 0;
}

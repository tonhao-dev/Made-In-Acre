/**
 * https://cses.fi/problemset/task/2189
 * Geometry, geometria, localizacao de um ponto
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
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

#define x first
#define y second
#define a_num f.f
#define a_den f.s
#define b s
#define LEFT 1
#define RIGHT -1
#define COLINEAR 0

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

typedef pll point;
typedef pair<pll, ll> line;
typedef vector<point> polygon;

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

ll cross(point u, point v) {
    return u.x * v.y - v.x * u.y;
}

ll dot(point u, point v) {
    return u.x * v.x + u.y * v.y;
}

ll norm(point u) {
    return dot(u, u);
}

double length(point u) {
    return sqrt(norm(u));
}

// angulo interno entre u e v (radianos)
double angle(point u, point v) {
    return acos(dot(u, v) / length(u) * length(v));
}

// angulo entre u e v, tendo z como origem
double angle_from(point u, point v, point z) {
    point vetor_zu = {u.x - z.x, u.y - z.y};
    point vetor_zv = {v.x - z.x, v.y - z.y};

    return angle(vetor_zu, vetor_zv);
}

// retorna o determinando entre os 2 pontos que formam
// a reta uv e um 3° ponto z
// matriz | x1 y1 1 | = (x2-x1)(y3-y1)-(x3-x1)(y2-y1)
//        | x2 y2 1 |
//        | x3 y3 1 |
// esse 1 é o valor do eixo X, eixo Y e
ll ccw(point u, point v, point z) {
    ll det = (v.x - u.x) * (z.y - u.y) - (z.x - u.x) * (v.y - u.y);
    return det;
}

ll is_left(point u, point v, point z) {
    ll det = ccw(u, v, z);

    if (det > 0) return LEFT;   // z esta a esquerda da reta que sai de u e chega em v
    if (det < 0) return RIGHT;  // z esta a direita da reta que sai de u e chega em v
    return COLINEAR;            // z e colinear a reta que sai de u e chega em v
}

int main(int argc, char** argv) {
    SPEED;

    ll test_cases;
    read(test_cases);

    rep(test_case, test_cases) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        ll loc = is_left({x1, y1}, {x2, y2}, {x3, y3});

        if (loc == LEFT)
            cout << "LEFT" << endl;
        else if (loc == RIGHT)
            cout << "RIGHT" << endl;
        else
            cout << "TOUCH" << endl;
    }

    return 0;
}

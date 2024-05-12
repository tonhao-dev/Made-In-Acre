// In the name of ALLAH
// https://codeforces.com/contest/623/standings/page/3
// By Shayan, contest: AIM Tech Round (Div. 1), problem: (A) Graph and String, Accepted
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

int const N = 1000 + 20;
int n, m, resp[N], degree[N], cnt;
bool mat[N][N], vis[N];
vector<vector<int>> adj(N);

void dfs1(int v) {
    cnt++;
    for (auto u : adj[v]) {
        if (resp[u] && resp[u] != resp[v]) {
            cout << "NO";
            exit(0);
        }
        if (!resp[u]) {
            resp[u] = resp[v];
            dfs1(u);
        }
    }

    return;
}

void dfs2(int v) {
    if (adj[v].size() != cnt - 1) {
        cout << "NO";
        exit(0);
    }
    vis[v] = 1;
    for (auto u : adj[v])
        if (!vis[u]) dfs2(u);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // 0-based
        u--, v--;

        mat[u][v] = mat[v][u] = true;
        degree[u]++, degree[v]++;
    }

    for (int i = 0; i < n; i++)
        // A -> 1
        // B -> 2
        // C -> 3
        // Se o vertice esta conectado a todos os outros entao ele eh B
        if (degree[i] == n - 1) resp[i] = 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (resp[i] || resp[j]) continue;

            // Pega um par de vertice conectados nao marcados com nenhuma letra
            if (mat[i][j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int cc = 0;
    for (int i = 0; i < n; i++) {
        // Se o vertice esta marcado com B, nao faz nada
        if (resp[i] == 2) continue;

        // Se o vertice nao possui letra
        if (!resp[i]) {
            if (!cc)
                resp[i] = 1;
            else if (cc == 1)
                resp[i] = 3;
            else
                return cout << "NO", 0;
            cnt = 0;
            dfs1(i);
            dfs2(i);
            cc++;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << char('a' + resp[i] - 1);

    return 0;
}
/*
8 20
1 4
2 3
5 8
6 7
1 5
1 6
1 7
1 8
2 5
2 6
2 7
2 8
3 5
3 6
3 7
3 8
4 5
4 6
4 7
4 8

9
24
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
2 3
2 4
2 5
2 6
2 7
2 8
2 9
3 4
3 5
3 6
4 5
4 6
5 6
7 8
8 9
7 9
*/

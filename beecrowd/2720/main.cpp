#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first > b.first;

    return a.second < b.second;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> presentes(n);
        for (int i = 0; i < n; i++) {
            int id, altura, largura, comprimento;
            cin >> id >> altura >> largura >> comprimento;

            presentes[i] = make_pair(altura * largura * comprimento, id);
        }

        sort(presentes.begin(), presentes.end(), comp);

        vector<int> ids;
        for (int i = 0; i < k; i++) ids.push_back(presentes[i].second);

        sort(ids.begin(), ids.end());

        for (int i = 0; i < k; i++) {
            if (i == k - 1) {
                cout << ids[i] << endl;
            } else {
                cout << ids[i] << " ";
            }
        }
    }

    return 0;
}

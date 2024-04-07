/**
 *  Problema B - Cruzamento
 * Adhoc, greedy
 */

#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int main() {
    int n; cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    int i = 0, j = n - 1;
    int ans = 0;
    while(i < j) {
        int filho = (h[i] + h[j]) / 2;
        ans = max(ans, filho);
        i++;
        j--;
    }

    cout << ans << endl;

    return 0;
}

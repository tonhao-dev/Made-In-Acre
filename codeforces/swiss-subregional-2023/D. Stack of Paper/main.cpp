#include <bits/stdc++.h>

using namespace std;

int main () {
    int n,m,aux = 0; cin >> n;
    string r = "Phew";
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    m = a[0];
    set<int> set1(a.begin(), a.end());
    if(set1.size() == 1) {
        cout << r << endl;
        return 0;
    }
    for(int i = 1; i < a.size(); i++) {
        if(a[i -1] > a[i]) {
            aux++;
            if(a[i] > m) {
                r = "Lie";
                break;
            }
            for(int j = i + 1; j<a.size(); j++) {
                if(a[j] > m || a[j-1] > a[j]) {
                    r = "Lie";
                    break;
                }
            }
            break;
        }
    }
    cout << r << endl;
    return 0;
}

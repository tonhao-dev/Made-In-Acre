#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, a, b, d;
    cin >> c >> a >> b;
    d = c - (a + b);
    vector<int> ages = {a, b, d};
    cout << *max_element(ages.begin(), ages.end()) << endl;

    return 0;
}

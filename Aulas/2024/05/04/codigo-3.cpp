#include <bits/stdc++.h>

using namespace std;

int somar_array(vector<int>& a, int i) {
    if (i == a.size() - 1) return a[i];

    return a[i] + somar_array(a, i + 1);
}

int main() {
    int soma = 0;
    //               i + ...
    vector<int> a = {1, 2, 3, 4, 5};

    cout << somar_array(a, 0) << endl;

    return 0;
}

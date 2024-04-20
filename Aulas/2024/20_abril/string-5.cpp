#include <bits/stdc++.h>

using namespace std;

int main() {
    string a = "impossivel";
    string b = "ssivelimpo";

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    if (a == b) {
        cout << "eh anagrama" << endl;
    } else {
        cout << "nao eh anagrama" << endl;
    }

    return 0;
}

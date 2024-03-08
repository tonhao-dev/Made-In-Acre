#include <iostream>

using namespace std;

int main() {
    int m, a, b, c;
    cin >> m >> a >> b;
    c = m - (a + b);
    cout << max(a, max(b, c)) << endl;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    int x;
    cin >> x;
    x = x % 2 == 0 ? x + 1 : x;
    for (int i = 0; i < 6; i++, x += 2) cout << x << endl;
    return 0;
}

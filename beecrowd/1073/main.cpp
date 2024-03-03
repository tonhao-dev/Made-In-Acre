#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i += 2) cout << i << "^2 = " << i * i << endl;
    return 0;
}

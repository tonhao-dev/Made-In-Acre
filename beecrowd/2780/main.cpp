#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n <= 800) cout << 1 <<endl;
    else if(n <= 1400) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}

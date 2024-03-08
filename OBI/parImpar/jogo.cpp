#include <iostream>

using namespace std;

int main() {
    int p, d,dd;
    cin >> p >> d >> dd;
    if(p == 0  && (d+dd)%2 == 0)  cout << 0 << endl;
    else if(p == 1  && (d+dd)%2 != 0)  cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}

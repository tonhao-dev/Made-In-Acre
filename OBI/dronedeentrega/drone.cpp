#include <iostream>

using namespace std;

int main() {
    int a,b,c, h, l, min1, min2;
    cin >> a >> b >> c >> h >> l;
    min1 = min(a,b);
    min2 = min(max(a,b), c);
    if((min1 <= h && min2 <= l) || (min2 <=h && min1 <=l)) cout << "S" << endl;
    else cout << "N" << endl;
    return 0;
}

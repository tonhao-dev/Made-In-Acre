#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int n;
    float a, b, c;
    cin >> n;
    cout << fixed << setprecision(1);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << (a * 2 + b * 3 + c * 5) / 10 << endl;
    }
    return 0;
}

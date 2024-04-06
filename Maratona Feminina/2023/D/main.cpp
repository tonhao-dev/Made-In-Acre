/**
 *  Problema D - Constante Mística do Universo
 * Adhoc, matemática
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    double m1, m2, x1, x2, f;
    cin >> m1 >> m2 >> x1 >> x2 >> f;

    double dist = abs(x1 - x2);

    double ans = ((dist * dist) * f) / (m1 * m2);

    cout << setprecision(10) << fixed << ans << endl;

    return 0;
}

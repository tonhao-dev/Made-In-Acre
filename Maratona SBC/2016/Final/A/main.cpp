#include <climits>
#include <iostream>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int menor = INT_MAX / 2;

    if (abs((a + b) - (c + d)) < menor) menor = abs((a + b) - (c + d));
    if (abs((a + c) - (b + d)) < menor) menor = abs((a + c) - (b + d));
    if (abs((b + c) - (a + d)) < menor) menor = abs((b + c) - (a + d));

    cout << menor << "\n";

    return 0;
}

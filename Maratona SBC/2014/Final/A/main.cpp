#include <iostream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
    vector<int> a(5);
    vector<int> b(5);

    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; ++i) {
        cin >> b[i];
    }

    bool ehCompativel = true;
    for (int i = 0; i < 5; ++i) {
        if (a[i] == true && b[i] == true) ehCompativel = false;
        if (a[i] == false && b[i] == false) ehCompativel = false;
    }

    char resp = ehCompativel ? 'Y' : 'N';

    cout << resp << "\n";

    return 0;
}

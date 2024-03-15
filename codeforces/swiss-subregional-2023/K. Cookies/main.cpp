#include <bits/stdc++.h>

using namespace std;

int main () {
    long long int n, a, b, resp = 2000;
    cin >> n >> a >> b;

    for(long long int i = 0; i <= n; i++) {
        for(long long int j = 0; j <= n; j++) {
            if((i * a + j * b) % n != 0) continue;
            if(i + j == 0) continue;
            resp = min(resp, i + j);
        }
    }
    cout << resp << endl;

    return 0;
}

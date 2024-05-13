#include <bits/stdc++.h>

using namespace std;

#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// https://judge.beecrowd.com/pt/problems/view/1980

int main() {
    speed;

    vector<ll> fatorial(16);
    fatorial[0] = 1;
    for(int i = 1; i < 16; i++) {
        // 2! = 2 * 1 = 2
        // 3! = 3 * 2! = 3 * 2 = 6
        // 4! = 4 * 3! = 4 * 6 = 24
        fatorial[i] = i * fatorial[i - 1];
    }

    for(auto f : fatorial) {
        cout << f << endl;
    }
    cout << endl;

    string palavra;
    while(true) {
        cin >> palavra;
        if(palavra == "0") break;

        cout << fatorial[palavra.size()] << endl;
    } 
    
    return 0;
}
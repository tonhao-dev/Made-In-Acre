#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m,n;

    while(cin >> n >>m && n != 0 && m != 0){
        vector<int> tickets(n+1, 0);
        for(int i=0; i<m; i++){
            int ticket;
            cin >> ticket;
            tickets[ticket]++;
        }

        int count = 0;
        for(int i=1; i<=n; i++){
            if(tickets[i] > 1) count++;
        }

        cout << count << endl;
    }
    return 0;
}

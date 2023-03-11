#include <iostream>
#include <cstdlib>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;


int main(int argc, char **argv)
{

    int x1,y1,x2,y2;

    while(1) {
        cin >>x1>>y1>>x2>>y2;

        if(x1 == 0){
            break;
        } else if(x1 == x2 && y1 == y2) {
            cout << 0;
        }else if(x1 == x2 || y1 == y2) {
            cout << 1;
        }else if(abs(x1-x2) == abs(y1-y2)) {
            cout << 1;
        }else {
            cout << 2;
        }
        cout << endl;
    }
    return 0;
}

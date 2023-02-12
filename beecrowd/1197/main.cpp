#include <iostream>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

// em um movimento acelerado a velocidade media é a velocidade no dobro do tempo

int main(int argc, char **argv)
{
    int velocity, time;
    // velocidade inicial e aceleração constante
    // qual deslocamento no dobro do tempo
    // ler velocidade e tempo
    // EOF => End Of Line

    while(cin >> velocity >> time) {
        int result = velocity * time * 2;
        cout << result << endl;
    }

    return 0;
}

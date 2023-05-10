#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int numBolas, numBolasFicou;
    while (cin >> numBolas >> numBolasFicou && numBolas != 0 && numBolasFicou != 0)
    {
        vector<int> valorBolas(numBolasFicou);
        vector<bool> somaPossivel(numBolas + 1, false);

        for (int i = 0; i < numBolasFicou; i++)
        {
            cin >> valorBolas[i];
        }

        for (int i = 0; i < numBolasFicou; i++)
        {
            for (int j = 0; j < numBolasFicou; j++)
            {
                somaPossivel[abs(valorBolas[i] - valorBolas[j])] = true;
            }
        }

        bool somouTodas = true;
        for (int i = 0; i <= numBolas; i++)
        {
            if (!somaPossivel[i])
            {
                somouTodas = false;
                cout << "N"
                     << "\n";
                break;
            }
        }

        if(somouTodas){
            cout << "Y"
             << "\n";
        }

    }

    return 0;
}

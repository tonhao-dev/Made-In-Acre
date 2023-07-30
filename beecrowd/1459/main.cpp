#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main(int argc, char **argv)
{
    int n;
    while (cin >> n)
    {
        map<int, vector<int>> m;
        multiset<int> s1;
        for (int i = 0; i < n; i++)
        {
            int x, z;
            cin >> x >> z;

            m[x].push_back(z);
            s1.insert(z);
        }
        int resp = 0;

        auto it = s1.begin();
        while (it != s1.end() || !s1.empty())
        {
            int valor = *it;
            auto it = m.begin();
            while (it->first <= valor)
            {
                for (int element : it->second)
                {

                    s1.erase(s1.find(element));
                }
                m.erase(it->first);
                ++it;
            }

            resp++;
            if (m.empty() || s1.empty())
            {
                break;
            }
        }
        std::cout << "resp: ";
        std::cout << resp << endl;
    }
    return 0;
}

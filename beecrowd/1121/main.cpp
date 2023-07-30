#include <iostream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

char INICIAL;
using namespace std;

bool verifyCel(char c)
{
    return c != '#';
}

bool verifyTam(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool verifyAlbum(char c)
{
    return c == '*';
}

void moveRight()
{

    if (INICIAL == 'N')
    {
        INICIAL = 'L';
    }
    else if (INICIAL == 'S')
    {
        INICIAL = 'O';
    }
    else if (INICIAL == 'L')
    {
        INICIAL = 'S';
    }
    else if (INICIAL == 'O')
    {
        INICIAL = 'N';
    }
}

void moveLeft()
{

    if (INICIAL == 'N')
    {
        INICIAL = 'O';
    }
    else if (INICIAL == 'S')
    {
        INICIAL = 'L';
    }
    else if (INICIAL == 'L')
    {
        INICIAL = 'N';
    }
    else if (INICIAL == 'O')
    {
        INICIAL = 'S';
    }
}

void moveFront(int &x, int &y)
{

    if (INICIAL == 'N')
    {
        x--;
    }
    else if (INICIAL == 'S')
    {
        x++;
    }
    else if (INICIAL == 'L')
    {
        y++;
    }
    else if (INICIAL == 'O')
    {
        y--;
    }
}

int main(int argc, char **argv)
{
    int n, m, s;
    while (cin >> n >> m >> s && n != 0 && m != 0 && s != 0)
    {
        char grid[n][m];
        int x, y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' || grid[i][j] == 'O')
                {
                    INICIAL = grid[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        char command[s];

        for (int i = 0; i < s; i++)
        {
            cin >> command[i];
        }

        int count = 0;

        for (char c : command)
        {
            int xAnt = x, yAnt = y;
            if (c == 'D')
            {
                moveRight();
            }
            else if (c == 'E')
            {
                moveLeft();
            }
            else if (c == 'F')
            {
                moveFront(xAnt, yAnt);
                if (verifyTam(xAnt, yAnt, n, m) && verifyCel(grid[xAnt][yAnt]))
                {
                    x = xAnt;
                    y = yAnt;
                    if (verifyAlbum(grid[x][y]))
                    {
                        count++;
                        grid[x][y] = '.';
                    }
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}

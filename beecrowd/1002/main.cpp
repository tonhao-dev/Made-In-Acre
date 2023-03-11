#include <iostream>
#include <iomanip>

#define debug(message, x) cout << message << x << endl

using namespace std;

int main(int argc, char **argv)
{
  double PI = 3.14159;
  double r = 0.00;

  cin >> r;
  cout << fixed << setprecision(4);
  cout << "A=" << PI * r * r << endl;
  return 0;
}

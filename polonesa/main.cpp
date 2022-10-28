#include <bits/stdc++.h>

using namespace std;

int main()
{
    string entrada;
    cin >> entrada;

    stack<char> operandos;

    for(auto i: entrada){
      if(isalpha(i)){
        cout << i;
      } else {
        if(i == ')'){
            while(operandos.top() != '('){
                cout << operandos.top();
                operandos.pop();
            }
            operandos.pop();
        } else {
            operandos.push(i);
        }
      }
    }
    return 0;
}
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;
int main()
{
  string fita;

  while (cin >> fita)
  {
    string resp;

    int cont = 0;
    stack<char> pilha;

    for (int i = 0; i < fita.size(); i++)
    {
      if (fita[i] == 'S')
        resp += 'B';
      else if (fita[i] == 'B')
        resp += 'S';
      else if (fita[i] == 'C')
        resp += 'F';
      else if (fita[i] == 'F')
        resp += 'C';
    }
    // cout << resp << endl;
    for (int i = 0; i < fita.size(); i++)
    { // puts("entrou F");
      // A duvida esta nessa verificação
      // pilha.top() != resp[i]
      if (pilha.empty() || pilha.top() != resp[i])
      {
        pilha.push(fita[i]);
      } // puts("colocou");}

      else
      {
        while (true)
        { // puts("entrou W");

          if (pilha.empty())
          {
            i--; // puts("saiu");
            break;
          }

          else if (resp[i] == pilha.top())
          {
            cont++; // puts("tirou");
            pilha.pop();
            i++;
            // puts("AQUI!!");
          }

          else
          {

            i--; // puts("saiu");
            break;
          }

          if (i >= resp.size())
          {
            i--; // puts("saiu I");
            break;
          }
        }
      }
    }

    printf("%d\n", cont);
  }

  return 0;
}
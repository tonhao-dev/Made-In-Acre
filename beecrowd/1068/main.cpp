#include <iostream>
#include <stack>

using namespace std;

int main() {
    string line;
    while(getline(cin, line)) {
        stack<char> pilha;
        bool ok = true;
        for(int i = 0; i < line.size(); i++) {
            if(line[i] == '(') {
                pilha.push('(');
            } else if(line[i] == ')') {
                if(pilha.empty()) {
                    ok = false;
                    break;
                } else {
                    pilha.pop();
                }
            }
        }
        if(!pilha.empty()) {
            ok = false;
        }
        if(ok) {
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }
    return 0;
}

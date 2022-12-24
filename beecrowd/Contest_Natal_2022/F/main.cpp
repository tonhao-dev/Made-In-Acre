#include <iostream>
#include <sstream>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main() {
    string input, word;
    vector<string> words;

    getline(cin, input);

    stringstream stream(input);

    while (getline(stream, word, ' '))
        words.push_back(word);

    if (words.size() == 1) {
        cout << words[0] << endl;
        return 0;
    }

    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i] == "blue") {
            cout << "azul ";
        } else if (words[i] == "red") {
            cout << "vermelho ";
        } else {
            cout << words[i] << " ";
        }
    }

    cout << words[words.size() - 1] << "\n";

    return 0;
}

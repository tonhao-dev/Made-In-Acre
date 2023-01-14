#include <iostream>
#include <set>
#include <string>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

int main(int argc, char **argv) {
  set<int> firstLetter;
  string word;

  getline(cin, word);
  while(word != "*") {
      for(int i = 0; i < word.size(); i++) {
          if(i == 0 || word.at(i - 1) == ' ')
            firstLetter.insert(tolower(word[i]));
      }

      if(firstLetter.size() == 1) cout << "Y" << endl;
      else cout << "N" << endl;

      getline(cin, word);
      firstLetter.clear();
  }

  return 0;
}

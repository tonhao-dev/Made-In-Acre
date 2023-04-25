#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int countCifra, countText;

    while (cin >> countCifra >> countText) {
        char cifraA[countCifra];
        char cifraB[countCifra];

        cin >> cifraA >> cifraB;
        cin.ignore();

        vector<string> texts(countText);
        for (int i = 0; i < countText; i++) {
            getline(cin, texts[i]);
        }

        for (auto text : texts) {
            for (int i = 0; i < text.length(); i++) {
                int indexCifraB = -1;
                int indexCifraA = -1;

                for (int j = 0; j < countCifra; j++) {
                    if (tolower(text[i]) == tolower(cifraB[j])) {
                        indexCifraB = j;
                        break;
                    }

                    if (tolower(text[i]) == tolower(cifraA[j])) {
                        indexCifraA = j;
                        break;
                    }
                }

                if (indexCifraB == -1 && indexCifraA == -1) {
                    cout << text[i];
                    continue;
                }

                char subsCifra[1];

                if (indexCifraB != -1) {
                    subsCifra[0] = cifraA[indexCifraB];
                } else if (indexCifraA != -1) {
                    subsCifra[0] = cifraB[indexCifraA];
                }

                if (isupper(text[i])) {
                    cout << (char)toupper(subsCifra[0]);
                } else {
                    cout << (char)tolower(subsCifra[0]);
                }
            }

            cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}

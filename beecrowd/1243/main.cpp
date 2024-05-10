#include <bits/stdc++.h>

using namespace std;

bool is_word(string word) {
    if (word == ".") return false;

    for (int i = 0; i < word.size(); i++) {
        if (!isalpha(word[i]) && word[i] != '.')
            return false;

        if (word[i] == '.' && i != word.size() - 1) return false;
    }

    return true;
}

int count_letters(string word) {
    int sum = 0;
    for (auto letter : word) {
        if (isalpha(letter)) sum++;
    }
    return sum;
}

int main() {
    string linha;
    while (getline(cin, linha)) {
        stringstream entrada(linha);
        string word;

        int count_words = 0;
        int count_letter = 0;
        while (getline(entrada, word, ' ')) {
            if (!is_word(word)) continue;

            count_words++;
            count_letter += count_letters(word);
        }

        if (count_words == 0) {
            cout << 250 << endl;
            continue;
        }

        int average = count_letter / count_words;

        if (average <= 3) {
            cout << 250 << endl;
        } else if (average <= 5) {
            cout << 500 << endl;
        } else {
            cout << 1000 << endl;
        }
    }

    return 0;
}

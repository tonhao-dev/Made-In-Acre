#include <iostream>
#include <string>

using namespace std;

int main() {
    string transcription;
    cin >> transcription;

    if(transcription == "XXO" || transcription == "OXX") {
        cout << "Alice" << endl;
        return 0;
    }

    if(transcription == "XOX") {
        cout << "*" << endl;
        return 0;
    }

    cout << "?" << endl;

    return 0;
}

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

enum HandType { Set = 0,
                Pair,
                NoPair,
};

HandType getHandType(vector<int> &hand) {
    if (hand[0] == hand[1] && hand[1] == hand[2]) return HandType::Set;

    if (hand[0] == hand[1] || hand[1] == hand[2] || hand[0] == hand[2]) return HandType::Pair;

    return HandType::NoPair;
}

int getPairCard(vector<int> &hand) {
    if (hand[0] == hand[1]) return hand[0];
    if (hand[1] == hand[2]) return hand[1];

    return hand[0];
}

int getUnmatchedPairCard(vector<int> &hand) {
    if (hand[0] == hand[1]) return hand[2];
    if (hand[1] == hand[2]) return hand[0];

    return hand[1];
}

vector<int> getWinnerHand(vector<int> &hand) {
    HandType type = getHandType(hand);
    vector<int> winnerHand(3, -1);

    // Set de 13 -> *
    if (type == HandType::Set && hand[0] == 13) {
        return winnerHand;
    }

    if (type == HandType::Set) {
        winnerHand[0] = hand[0] + 1;
        winnerHand[1] = hand[1] + 1;
        winnerHand[2] = hand[2] + 1;

        return winnerHand;
    }

    if (type == HandType::Pair) {
        int pairCard = getPairCard(hand);
        int unMatchedPairCard = getUnmatchedPairCard(hand);
        // 13 13 12
        if (pairCard == 13 && find(hand.begin(), hand.end(), 12) != hand.end()) {
            winnerHand[0] = 1;
            winnerHand[1] = 1;
            winnerHand[2] = 1;

            return winnerHand;
        }

        // 1 2 2 -> 2 2 3
        if (pairCard == unMatchedPairCard + 1) {
            winnerHand[0] = pairCard;
            winnerHand[1] = pairCard;
            winnerHand[2] = unMatchedPairCard + 2;

            return winnerHand;
        }

        // 1 1 13 -> 2 2 1
        if (unMatchedPairCard == 13) {
            winnerHand[0] = pairCard + 1;
            winnerHand[1] = pairCard + 1;
            winnerHand[2] = 1;

            return winnerHand;
        }

        // 1 1 2 -> 1 1 3
        winnerHand[0] = pairCard;
        winnerHand[1] = pairCard;
        winnerHand[2] = unMatchedPairCard + 1;

        return winnerHand;
    }

    winnerHand[0] = 1;
    winnerHand[1] = 1;
    winnerHand[2] = 2;

    return winnerHand;
}

int main(int argc, char **argv) {
    vector<int> mao_entrada(3, -1);
    while (mao_entrada[0] != 0) {
        for (int i = 0; i < 3; ++i) cin >> mao_entrada[i];

        if (mao_entrada[0] == 0) return 0;

        vector<int> winnerHand = getWinnerHand(mao_entrada);

        if (winnerHand[0] == -1) {
            cout << "*" << endl;
            continue;
        }

        sort(winnerHand.begin(), winnerHand.end());

        // Muito importante!
        sort(winnerHand.begin(), winnerHand.end());

        cout << winnerHand[0] << " " << winnerHand[1] << " " << winnerHand[2] << "\n";
    }

    return 0;
}

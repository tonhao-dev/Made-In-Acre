#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int kBoardSize = 9;

void PrintVector(const vector<int>& vec) {
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

bool VerifyQuadrant(const vector<vector<int>>& board, int row_start, int col_start) {
    vector<bool> quadrant(kBoardSize, false);
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            int num = board[i][j];
            if (num != 0 && quadrant[num-1]) {
                return false;
            }
            quadrant[num-1] = true;
        }
    }
    return true;
}

bool VerifyRow(const vector<vector<int>>& board, int row) {
    vector<bool> used(kBoardSize, false);
    for (int i = 0; i < kBoardSize; i++) {
        int num = board[row][i];
        if (num != 0 && used[num-1]) {
            return false;
        }
        used[num-1] = true;
    }
    return true;
}

bool VerifyCol(const vector<vector<int>>& board, int col) {
    vector<bool> used(kBoardSize, false);
    for (int i = 0; i < kBoardSize; i++) {
        int num = board[i][col];
        if (num != 0 && used[num-1]) {
            return false;
        }
        used[num-1] = true;
    }
    return true;
}

bool VerifyBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < kBoardSize; i++) {
        if (!VerifyRow(board, i) || !VerifyCol(board, i)) {
            return false;
        }
    }
    for (int i = 0; i <= 6; i += 3) {
        for (int j = 0; j <= 6; j += 3) {
            if (!VerifyQuadrant(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int num_cases;
    cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++) {
        vector<vector<int>> board(kBoardSize, vector<int>(kBoardSize));
        for (int i = 0; i < kBoardSize; i++) {
            for (int j = 0; j < kBoardSize; j++) {
                cin >> board[i][j];
            }
        }
        cout << "Instancia " << case_num << endl;
        if (VerifyBoard(board)) {
            cout << "SIM\n\n";
        } else {
            cout << "NAO\n\n";
        }
    }
    return 0;
}

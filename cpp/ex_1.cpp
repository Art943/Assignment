#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_set>

bool isValidRow(const std::vector<int>& boardRow) {
    std::unordered_set<int> seen;
    int prev = 0; // To keep track of the previous digit

    for (int num : boardRow) {
        if (num != 0) {
            if (seen.find(num) != seen.end() || std::abs(num - prev) == 2) {
                return false; // Duplicate or 3 or 5 next to each other in row
            }
            seen.insert(num);
            prev = num;
        }
    }
    return true;
}

bool isValidCol(const std::vector<std::vector<int>>& board, int col) {
    std::unordered_set<int> seen;
    int prev = 0; // To keep track of the previous digit

    for (const auto& row : board) {
        int num = row[col];
        if (num != 0) {
            if (seen.find(num) != seen.end() || std::abs(num - prev) == 2) {
                return false; // Duplicate or 3 or 5 next to each other in column
            }
            seen.insert(num);
            prev = num;
        }
    }
    return true;
}



bool isValidSudoku(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        if (!isValidRow(row)) {
            return false;
        }
    }

    for (int col = 0; col < 9; ++col) {
        if (!isValidCol(board, col)) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ifstream inputFile("sudoku_input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    int validCount = 0;

    for (int boardNum = 0; boardNum < 1000; ++boardNum) {
        std::vector<std::vector<int>> sudokuBoard;
        sudokuBoard.reserve(9);

        for (int row = 0; row < 9; ++row) {
            std::vector<int> boardRow;
            boardRow.reserve(9);

            for (int col = 0; col < 9; ++col) {
                int digit;
                inputFile >> digit;
                boardRow.push_back(digit);
            }

            sudokuBoard.push_back(boardRow);
        }

        if (isValidSudoku(sudokuBoard)) {
            ++validCount;
        }
    }

    inputFile.close();

    std::cout << "Number of valid Sudoku boards: " << validCount << "\n";

    return 0;
}
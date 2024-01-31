/*#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
int size;
typedef struct 
{
    char *name;

    uint8_t age;
}person_t;
void main()
{
    person_t a;
    printf("Please enter the alocated size of memmory for the name: ");
    scanf("%d",&size);
    a.name = malloc(size);
    printf("\n Please enter name and age:");
    scanf("%s %d",a.name, &a.age);
    printf("\n%s %d",a.name,a.age);
     void free(void *name);
}*/
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to check if a set of numbers is valid (no duplicates)
bool isValidSet(char nums[SIZE]) {
    bool seen[SIZE + 1] = {false}; // Indices 1 to 9 represent digits 1 to 9

    for (int i = 0; i < SIZE; i++) {
        if (nums[i] != '.') {
            int digit = nums[i] - '0';

            // Check if the digit is in the valid range and hasn't been seen before
            if (digit < 1 || digit > 9 || seen[digit]) {
                return false;
            }

            seen[digit] = true;
        }
    }

    return true;
}

// Function to check if a Sudoku board is valid
bool isValidSudoku(char board[SIZE][SIZE]) {
    // Check each row
    for (int i = 0; i < SIZE; i++) {
        if (!isValidSet(board[i])) {
            return false;
        }
    }

    // Check each column
    for (int j = 0; j < SIZE; j++) {
        char column[SIZE];
        for (int i = 0; i < SIZE; i++) {
            column[i] = board[i][j];
        }

        if (!isValidSet(column)) {
            return false;
        }
    }

    // Check each 3x3 subgrid
    for (int blockRow = 0; blockRow < SIZE; blockRow += 3) {
        for (int blockCol = 0; blockCol < SIZE; blockCol += 3) {
            char square[SIZE];
            int index = 0;
            for (int i = blockRow; i < blockRow + 3; i++) {
                for (int j = blockCol; j < blockCol + 3; j++) {
                    square[index++] = board[i][j];
                }
            }

            if (!isValidSet(square)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Example valid Sudoku board
    char validBoard[SIZE][SIZE] = {
    {'8', '1', '9', '2', '3', '4', '5', '7', '6'},
        {'2', '4', '5', '6', '1', '7', '3', '9', '8'},
        {'7', '3', '6', '8', '5', '9', '2', '1', '4'},
        {'1', '5', '8', '9', '7', '3', '6', '4', '2'},
        {'3', '2', '4', '1', '8', '6', '7', '5', '9'},
        {'6', '9', '7', '5', '4', '2', '8', '3', '1'},
        {'4', '8', '2', '3', '9', '5', '1', '6', '7'},
        {'5', '7', '1', '4', '6', '8', '9', '2', '3'},
        {'9', '6', '3', '7', '2', '1', '4', '8', '5'}

    };

    // Check if the example board is valid
    if (isValidSudoku(validBoard)) {
        printf("The Sudoku board is valid.\n");
    } else {
        printf("The Sudoku board is not valid.\n");
    }

    return 0;
}
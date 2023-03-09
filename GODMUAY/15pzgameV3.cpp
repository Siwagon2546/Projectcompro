#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

// Define the puzzle as a vector of vectors
vector<vector<int>> puzzle;

// Define the coordinates of the blank space
int blank_row, blank_col;

// Function to initialize the puzzle with random numbers
void init_puzzle(int size) {
    // Define a vector of numbers from 1 to size^2 - 1
    vector<int> nums(size * size - 1);
    for (int i = 0; i < size * size - 1; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the numbers randomly
    random_device rd;
    mt19937 g(rd());
    shuffle(nums.begin(), nums.end(), g);

    // Initialize the puzzle with the shuffled numbers and the blank space at the bottom right
    int index = 0;
    puzzle.resize(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (index < size * size - 1) {
                puzzle[i][j] = nums[index];
            } else {
                puzzle[i][j] = 0;
                blank_row = i;
                blank_col = j;
            }
            index++;
        }
    }
}

// Function to print the puzzle
void print_puzzle() {
    cout << endl;
    int max_num_width = to_string(puzzle.size() * puzzle.size() - 1).size();
    for (int i = 0; i < puzzle.size(); i++) {
        // Print the top border of the row
        for (int k = 0; k < puzzle[i].size() * (max_num_width + 3) + 1; k++) {
            cout << "-";
        }
        cout << endl;

        // Print the row itself
        for (int j = 0; j < puzzle[i].size(); j++) {
            cout << "| ";
            if (puzzle[i][j] == 0) {
                cout << string(max_num_width, ' ');
            } else {
                cout << setw(max_num_width) << puzzle[i][j];
            }
            cout << " ";
        }
        cout << "|" << endl;
    }

    // Print the bottom border of the puzzle
    for (int k = 0; k < puzzle[0].size() * (max_num_width + 3) + 1; k++) {
        cout << "-";
    }
    cout << endl << endl;
}

// Function to move a tile
void move_tile(int num) {
    // Find the coordinates of the tile
    int row = -1, col = -1;
    for (int i = 0; i < puzzle.size(); i++) {
        for (int j = 0; j < puzzle[i].size(); j++) {
            if (puzzle[i][j] == num) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1) {
            break;
        }
    }

    // Check if the tile is adjacent to the blank space
    if ((row == blank_row && abs(col - blank_col) == 1) ||
        (col == blank_col && abs(row - blank_row) == 1)) {
        // Swap the tile with the blank space
        swap(puzzle[row][col], puzzle[blank_row][blank_col]);
        blank_row = row;
        blank_col = col;
    }
}

int main() {
    // Get user input for puzzle size
    int size;
    cout << "Enter the size of the puzzle: ";
    cin >> size;

    // Initialize the puzzle
    init_puzzle(size);

    // Print the initial puzzle
    print_puzzle();

    // Game loop
    while (true) {
        // Get user input for tile to move
        int num;
        cout << "Enter the number of the tile you want to move: ";
        cin >> num;

        // Move the tile
        move_tile(num);

        // Print the updated puzzle
        print_puzzle();
    }

    return 0;
}
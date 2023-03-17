#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <windows.h>

using namespace std;

// Function to print the puzzle board
void printPuzzle(const vector<int>& puzzle, int size)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    // Print the top border of the puzzle board
    SetConsoleTextAttribute(hConsole, 5);
    cout << "\t+";
    for (int j = 0; j < size; j++) {
        cout << "----+";
        //cout << "     ";
    }
    SetConsoleTextAttribute(hConsole,15);
    cout << endl;
    SetConsoleTextAttribute(hConsole, 5);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Print a vertical line before each tile except the first
            if (j == 0) {
                SetConsoleTextAttribute(hConsole, 5);
                cout << "\t| ";
                //cout << "\t  ";
                SetConsoleTextAttribute(hConsole, 15);
            }
    SetConsoleTextAttribute(hConsole, 15);
            int value = puzzle[i * size + j];
    SetConsoleTextAttribute(hConsole, 10);
            if (value == 0) {
                cout << "   ";
            } else {
                cout << setw(3) << value;
            }
    SetConsoleTextAttribute(hConsole, 15);
    SetConsoleTextAttribute(hConsole, 5);
            // Print a vertical line after each tile except the last
            cout << "| ";
            //cout << "  ";
        }
        SetConsoleTextAttribute(hConsole, 15);
        cout << endl;

        // Print a horizontal line after each row except the last
        SetConsoleTextAttribute(hConsole, 5);
        if (i != size - 1) {
            cout << "\t+";
            //cout << "\t ";
            for (int j = 0; j < size; j++) {
                cout << "----+";
            }
            SetConsoleTextAttribute(hConsole, 15);
            cout << endl;
        }
    }

    // Print the bottom border of the puzzle board
    SetConsoleTextAttribute(hConsole, 5);
    cout << "\t+";
    //cout << "\t ";
    SetConsoleTextAttribute(hConsole, 15);
    SetConsoleTextAttribute(hConsole, 5);
    for (int j = 0; j < size; j++) {
        cout << "----+";
        //cout << "     ";
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}

// Function to check if the puzzle is in a winning state
bool checkWin(const vector<int>& puzzle, int size)
{
    for (int i = 0; i < size * size - 1; i++) {
        if (puzzle[i] != i + 1) {
            return false;
        }
    }
    return true;
}

// Function to move a tile in the puzzle
void moveTile(vector<int>& puzzle, int size, int tile)
{
    // Find the position of the tile
    int pos = find(puzzle.begin(), puzzle.end(), tile) - puzzle.begin();

    // Find the position of the empty space
    int empty = find(puzzle.begin(), puzzle.end(), 0) - puzzle.begin();

    // Check if the tile can be moved
    if ((pos % size != 0 && pos - 1 == empty) || // left
        (pos % size != size - 1 && pos + 1 == empty) || // right
        (pos >= size && pos - size == empty) || // up
        (pos < size * (size - 1) && pos + size == empty)) // down
    {
        // Swap the tile and the empty space
        swap(puzzle[pos], puzzle[empty]);
    }
}

// Function to play the puzzle game
int playPuzzle(int size)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Create the puzzle board
    vector<int> puzzle(size * size - 1);

    // Fill the puzzle board with numbers 1 through size*size-1
    for (int i = 0; i < size * size - 1; i++) {
        puzzle[i] = i + 1;
    }

    // Shuffle the puzzle board
    random_device rd;
    mt19937 g(rd());
    shuffle(puzzle.begin(), puzzle.end(), g);

    // Add the empty space to the puzzle board
    puzzle.push_back(0);

    // Play the puzzle game
    while (!checkWin(puzzle, size)) {
        // Print the puzzle board
        cout << "Current puzzle:" << endl;
        printPuzzle(puzzle, size);

        // Get user input
        int tile;
        string inp;
        SetConsoleTextAttribute(hConsole, 9);
        cout <<  endl <<"Enter tile to move (Type EXIT to exit): ";
        SetConsoleTextAttribute(hConsole, 15);
        cin >> inp;


        if(inp == "EXIT"){
            system("cls");
            cout << endl << endl <<"\tEXIT" ;
            Sleep(1500);    

            return 0;
        }

        // Quit the game if the user enters 0
        /* if (tile == 0) {
            return;
        } */
        tile = atoi(inp.c_str());

        // Move the tile
        moveTile(puzzle, size, tile);
    }

    // Print the winning message
    cout << "Congratulations! You solved the puzzle!" << endl;
    return 1;
}

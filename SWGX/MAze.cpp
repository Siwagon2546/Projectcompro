#include <iostream>
#include <conio.h> // for getch() function

using namespace std;

const int ROWS = 10;
const int COLS = 20;

// The maze is represented as a 2D array of characters
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
};

// The player's position
int playerRow = 1;
int playerCol = 1;

// The goal position
int goalRow = ROWS - 2;
int goalCol = COLS - 2;

// Draw the maze
void drawMaze() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == playerRow && col == playerCol) {
                cout << "P"; // draw the player
            } else if (row == goalRow && col == goalCol) {
                cout << "G"; // draw the goal
            } else {
                cout << maze[row][col]; // draw the maze
            }
        }
        cout << endl;
    }
}

// Move the player
void movePlayer(int rowOffset, int colOffset) {
    int newRow = playerRow + rowOffset;
    int newCol = playerCol + colOffset;
    if (maze[newRow][newCol] == ' ') {
        playerRow = newRow;
        playerCol = newCol;
    }
}
    // Game loop
int main(){
while (true) {
    // Draw the maze
    char input;
    system("cls"); // clear the console
    drawMaze();

    // Get input from the player
    input = getch();
    switch (input) {
        case 'w':
            movePlayer(-1, 0);
            break;
        case 'a':
            movePlayer(0, -1);
            break;
        case 's':
            movePlayer(1, 0);
            break;
        case 'd':
            movePlayer(0, 1);
            break;
        case 'q':
            return 0; // quit the game
        default:
            break;
    }

    // Check if the player has reached the goal
    if (playerRow == goalRow && playerCol == goalCol) {
        cout << "You win!" << endl;
        break;
    }
}
return 0;
}

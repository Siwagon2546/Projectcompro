#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <random>

using namespace std;

int height, width;
vector<vector<int>> maze;

vector<int> generateRandomDirections() {
    vector<int> randoms {1, 2, 3, 4};
    random_shuffle(randoms.begin(), randoms.end());
    return randoms;
}

void recursion(int r, int c) {
    vector<int> randDirs = generateRandomDirections();
    for (int i = 0; i < randDirs.size(); i++) {
        switch (randDirs[i]) {
            case 1: // Up
                if (r - 2 < 0)
                    continue;
                if (maze[r - 2][c] != 0) {
                    maze[r - 2][c] = 0;
                    maze[r - 1][c] = 0;
                    recursion(r - 2, c);
                }
                break;
            case 2: // Right
                if (c + 2 >= width)
                    continue;
                if (maze[r][c + 2] != 0) {
                    maze[r][c + 2] = 0;
                    maze[r][c + 1] = 0;
                    recursion(r, c + 2);
                }
                break;
            case 3: // Down
                if (r + 2 >= height)
                    continue;
                if (maze[r + 2][c] != 0) {
                    maze[r + 2][c] = 0;
                    maze[r + 1][c] = 0;
                    recursion(r + 2, c);
                }
                break;
            case 4: // Left
                if (c - 2 < 0)
                    continue;
                if (maze[r][c - 2] != 0) {
                    maze[r][c - 2] = 0;
                    maze[r][c - 1] = 0;
                    recursion(r, c - 2);
                }
                break;
        }
    }
}

vector<vector<int>> generateMaze(int h, int w) {
    height = h;
    width = w;
    maze = vector<vector<int>>(height, vector<int>(width, 1));
    // Starting cell
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, height - 1);
    int r = dis(gen);
    while (r % 2 == 0) {
        r = dis(gen);
    }
    uniform_int_distribution<> dis2(0, width - 1);
    int c = dis2(gen);
    while (c % 2 == 0) {
        c = dis2(gen);
    }
    maze[r][c] = 0;
    recursion(r, c);
    return maze;
}

int playerRow = 1;
int playerCol = 1;

// The goal position


void drawMaze(int h,int w) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (row == playerRow && col == playerCol) {
                cout << "P"; // draw the player
            } else if (row == h-2 && col == w-2) {
                cout << "G"; // draw the goal
            } else {
                if(maze[row][col]==1){
                    cout<<"@";
                }else{
                    cout<<" ";
                }
                // draw the maze
            }
        }
        cout << endl;
    }
}

void movePlayer(int rowOffset, int colOffset) {
    int newRow = playerRow + rowOffset;
    int newCol = playerCol + colOffset;
    if (maze[newRow][newCol] == 0) {
        playerRow = newRow;
        playerCol = newCol;
    }
}

int main() {
    int h = 31, w = 31;
    int goalRow = h - 2;
    int goalCol = w - 2;
    vector<vector<int>> maze = generateMaze(h, w);
    while (true)
    {
    
    
    char input;
    system("cls"); // clear the console
    drawMaze(h,w);

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
    if (playerRow == goalRow && playerCol == goalCol) {
        cout << "You win!" << endl;
        break;
    }
    }
    return 0;
}
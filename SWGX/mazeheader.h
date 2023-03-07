#include <iostream>
#include <vector>
#include <algorithm> //shuffle
#include <conio.h>
#include <random>

using namespace std;

class maze{
    public:
    char input;
    bool win=false;
    int h;
    int w;
    int playerRow = 1;
    int playerCol = 1;
    int goalRow;
    int goalCol;
    vector<vector<int>> maze;
    vector<int> generateRandomDirections();
    void recursion(int,int);
    vector<vector<int>> generateMaze();
    void drawMaze();
    void movePlayer(int , int);
    void move();
    void wincheck();

};

void maze::move(){
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
            exit(0); // quit the game
        default:
            break;
    }
}


vector<int> maze::generateRandomDirections(){
    vector<int> randoms {1, 2, 3, 4};
    random_shuffle(randoms.begin(), randoms.end());
    return randoms;

}

void maze::recursion(int r, int c) {
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
                if (c + 2 >= w)
                    continue;
                if (maze[r][c + 2] != 0) {
                    maze[r][c + 2] = 0;
                    maze[r][c + 1] = 0;
                    recursion(r, c + 2);
                }
                break;
            case 3: // Down
                if (r + 2 >= h)
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


vector<vector<int>> maze::generateMaze() {
    maze = vector<vector<int>>(h, vector<int>(w, 1));
    // Starting cell
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, h - 1);
    int r = dis(gen);
    while (r % 2 == 0) {
        r = dis(gen);
    }
    uniform_int_distribution<> dis2(0, w - 1);
    int c = dis2(gen);
    while (c % 2 == 0) {
        c = dis2(gen);
    }
    maze[r][c] = 0;
    recursion(r, c);
    return maze;
}

void maze::drawMaze() {
    goalRow = h - 2;
    goalCol = w - 2;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
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
    cout<<win<< " "<<goalRow<<" "<<goalCol<< " "<<playerRow<<" "<<playerCol;
}

void maze::movePlayer(int rowOffset, int colOffset) {
    int newRow = playerRow + rowOffset;
    int newCol = playerCol + colOffset;
    if (maze[newRow][newCol] == 0) {
        playerRow = newRow;
        playerCol = newCol;
    }
}

void maze::wincheck(){
    if (playerRow == goalRow && playerCol == goalCol) {
        win=true;
        cout << "You win!" << endl;
        
    }
}



void mazeplay(int k){
    maze x;
    x.h=5*k;
    x.w=5*k;

    x.maze=x.generateMaze();
    
    while (!x.win){
    system("cls");
    x.drawMaze();
    x.move();
    x.wincheck();
    
    }

}
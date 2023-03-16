#include <iostream>
#include <windows.h>   // WinApi header
#include <vector>
#include <algorithm> //shuffle
#include <conio.h>
#include <random>

using namespace std;

class maze{
    public:
    char input;
    bool win=false;
    bool exitcheck=false;
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
    int exit_c();

};

void maze::move(){
    if(!exitcheck){
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
            exitcheck = true; // quit the game
        default:
            break;
    }
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
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    goalRow = h - 2;
    goalCol = w - 2;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            if (row == playerRow && col == playerCol) {
                SetConsoleTextAttribute(hConsole, 192);
                cout << " "; // draw the player
                SetConsoleTextAttribute(hConsole, 15);
            } else if (row == h-2 && col == w-2) {
                SetConsoleTextAttribute(hConsole, 96);
                cout << " "; // draw the goal
                SetConsoleTextAttribute(hConsole, 15);
            } else {
                if(maze[row][col]==1){
                    SetConsoleTextAttribute(hConsole, 160);
                    cout<<" ";
                    SetConsoleTextAttribute(hConsole, 15);
                }else{
                    cout<<" ";
                }
                // draw the maze
            }
        }
        cout << endl;
        
    }
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


int mazeplay(int k){
    maze x;

    if(k<10){
        x.h=2*k-1;
        x.w=4*k-1;
    }else{
        x.h=10;
        x.w=30;
    }

    x.maze=x.generateMaze();
    
    while (true){
    system("cls");
    x.drawMaze();
    x.move();
    x.wincheck();
    if(x.win){
        return 1;
    }else if(x.exitcheck){
        cout <<"exit\n";
        return 0;

    }

    }

}
#include <iostream>

using namespace std;

const int W = 70;

void Maze(char [][W],int,int);
void showMaze(char [][W],int,int);

int main(){
    char Maze_l[][W]={};
    Maze(Maze_l,10,10);
    showMaze(Maze_l,10,10);
}

void Maze(char Mazed[][W],int H,int W){
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            Mazed[i][j]='#';
        }

    }
}

void showMaze(char Mazed[][W],int Height,int Width){
    for(int i=0;i<Height;i++){
        for(int j=0;j<Width;j++){
            cout<<Mazed[i][j];
        }
        cout<<endl;
    }

}
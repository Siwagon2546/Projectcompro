#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <algorithm>

using namespace std;

const int width = 20;
const int height = 20;

int locationX, locationY;
int score;
bool gameOver;
int NumberX[5]={};
int NumberY[5]={};

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

vector<int> nums;

void GenerateLocation(){
    locationX = rand() % width;
    locationY = rand() % height;    
    for(int i=0;i<1;i++){
        NumberX[i] = rand()%5+1;
        NumberY[i] = rand()%3+1;
    }
    for(int i=1;i<2;i++){
        NumberX[i] = rand()%5+6;
        NumberY[i] = rand()%3+4;
    }
    for(int i=2;i<3;i++){
        NumberX[i] = rand()%5+11;
        NumberY[i] = rand()%3+7;
    }
    for(int i=3;i<4;i++){
        NumberX[i] = rand()%5+16;
        NumberY[i] = rand()%3+10;
    }
    for(int i=4;i<5;i++){
        NumberX[i] = rand()%5+21;
        NumberY[i] = rand()%3+13;
    }
    for(int i=5;i<6;i++){
        NumberX[i] = rand()%5+26;
        NumberY[i] = rand()%3+16;
    }
}

void Setup(){
    srand(time(NULL));
    gameOver = false;
    dir = STOP;
    score = 0;
    GenerateLocation();
}

void Draw(int num,int rand_num){
    // Create a vector of integers
    vector<int> number = {1, 2, 3};


    number[3]=num-number[0];
    number[4]=num-number[1];
    number[5]=num-number[2];

    cout << "            SMART Snake Game   \n";
    cout << "               Number is " <<    num   << "\n";
    cout << "     ^ UP , v DOWN , < LEFT , > RIGHT";
    system("cls");
    for (int i = 0; i < width*2+2; i++)
        cout << "_";
        cout << endl;
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0){
                cout << "|";
            }
            
            for(int k=0;k<6;k++){
            if (i == NumberY[k] && j == NumberX[k])
                cout << number[k];
            }    
            
                
            if (i == locationY && j == locationX){
                cout << "#";
            }else{cout << " ";}    
               
            
            bool foundNum = false;
            for (int k = 0; k < nums.size(); k++){
                if (nums[k] == score && !foundNum){
                    cout << score;
                    foundNum = true;
                }
            }
            if (!foundNum)
                cout << " ";

            if (j == width - 1)
                cout << "|";
        }
        cout << endl;
    }
    

    for (int i = 0; i < width*2+2; i++)
    cout << "_";
    cout << endl;

}  
void Input(){

    if (_kbhit()){
        switch (_getch()){
        case 75 : dir = LEFT;
            break;
        case 77 : dir = RIGHT;
            break;
        case 72 : dir = UP;
            break;
        case 80 : dir = DOWN;
            break;
        case 'x' : gameOver = true;
            break;
        }

    }

}

void Logic(){
    switch (dir){
    case LEFT : locationX--;
        break;
    case RIGHT : locationX++;
        break;
    case UP : locationY--;
        break;
    case DOWN : locationY++;
        break;
    }

    if (locationX < 0 || locationX >= width || locationY < 0 || locationY >= height)
        gameOver = true;
    
    /*bool foundNum = false;
    for (int k = 0; k < nums.size(); k++){
        if (nums[k] == score && !foundNum){
            if (score == locationX + locationY){
                score++;
                GenerateFruit();
            }
            foundNum = true;
        }
    }*/
}

int main(){
    vector<int> number = {1, 2, 3};
    // Seed the random number generator with the current time
    srand(time(nullptr)); 
    int num = rand()%6+5;
    // Generate a random number between 0 and 5
    int rand_num = rand() % 6;
    // Randomize the position of the random number in the vector
    random_shuffle(number.begin(), number.end());
    while (!gameOver)
    {   

        Draw(num,rand_num);
        Input();
        Logic();
    }

    return 0;
}
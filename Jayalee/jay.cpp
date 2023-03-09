#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <algorithm>

using namespace std;

const int width = 40;
const int height = 20;

int locationX=1, locationY=1;
//int score;
bool gameOver;
int NumberX[6]={};
int NumberY[6]={};
int k=0;
int number[6] = {};

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

vector<int> nums;
void GenerateLocation(){
    srand(time(0));
    int key=0,j=0; 
        for(int i=0;i<6;i++){
        NumberX[i] = rand()%(width-2)+2; 
        NumberY[i] = rand()%(height-1)+1;
        for(int j=0;j<i;j++){
            if(NumberX[i]==NumberX[j]||NumberY[i]==NumberY[j]){
                i--;
            }
        }
    }
    for(int i=0;i<sizeof(NumberY) / sizeof(int);i++){
        key=NumberY[i];
        j=i-1;
    while(j>=0 && NumberY[j]>key){
        NumberY[j+1]=NumberY[j];
        j-=1;
    }
    NumberY[j+1]=key;
    }
/*         for(int j=0;j<6;j++){
        cout<<"X"<<NumberX[j]<<endl;
        cout<<"Y"<<NumberY[j]<<endl;
    } */
}

void rand_number(int num){
    srand(time(0));
    int key=0,j=0;
        for(int i=0;i<3;i++){
        number[i] = rand()%6; 
        for(int j=0;j<i;j++){
            if(number[i]==number[j]){
                i--;
            }
        }
    }
    for(int i=0;i<(sizeof(number) / sizeof(int))-3;i++){
        key=number[i];
        j=i-1;
    while(j>=0 && number[j]>key){
        number[j+1]=number[j];
        j-=1;
    }
    number[j+1]=key;
    }
    number[3]=num-number[0];
    number[4]=num-number[1];
    number[5]=num-number[2];

}

void Setup(){
    int num;
    srand(time(NULL));
    gameOver = false;
    dir = STOP;
    GenerateLocation();
   // rand_number(num);
}

void Draw(int num,int rand_num){

    cout << "            SMART Snake Game   \n";
    cout << "               Number is " <<    num   << "\n";
    cout << "^ UP , v down , < LEFT , > RIGHT ,  x EXIT\n";
    GenerateLocation();
    rand_number(num);
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==0||i==height-1){
                cout<<"_";
            }else if(j==0||j==width-1){
                cout<<"|";
            }else if(i == locationY && j == locationX){
                cout << "#"; 
            }else{
             if(j == NumberX[k]&&i== NumberY[k]){
                    cout << number[k];
                    k++;
                }else{ 
                    cout << " ";
                }
            }
            
            bool foundNum = false;
            for (int k = 0; k < nums.size(); k++)
            {
                if (!foundNum)
                {

                    foundNum = true;
                }
            }
            if (!foundNum){}
 
        }
        cout << endl;
        }
        
    
    system("cls");
}

void snakeEat(){

}

void Input(){

    if (_kbhit())
    {
        switch (_getch())
        {
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
    switch (dir)
    {
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
    for (int k = 0; k < nums.size(); k++)
    {
        if (nums[k] == score && !foundNum){
            if (score == locationX + locationY)
            {
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
    srand(time(NULL));
    //For random number
    int num = rand()%6+5;
    // Generate a random number between 0 and 5
    int rand_num = rand() % 6;
    // Randomize the position of the random number in the vector
    random_shuffle(number.begin(), number.end());
    while (!gameOver)
    {   
        GenerateLocation();
        rand_number(num);
        Draw(num,rand_num);
        Input();
        Logic();
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

const int width = 20;
const int height = 20;

int locationX, locationY;
int score;
bool gameOver;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

vector<int> nums;

void GenerateLocation()
{
    locationX = rand() % width;
    locationY = rand() % height;
}

void Setup()
{
    srand(time(NULL));
    gameOver = false;
    dir = STOP;
    score = 0;
    GenerateLocation();
}

void Draw(int num)
{

    cout << "            SMART Snake Game   \n";
    cout << "               Number is " <<    num   << "\n";
    system("cls");
    for (int i = 0; i < width*2+2; i++)
        cout << "_";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "|";
            if (i == locationY && j == locationX)
                cout << "#";
            else
                cout << " ";

            bool foundNum = false;
            for (int k = 0; k < nums.size(); k++)
            {
                if (nums[k] == score && !foundNum)
                {
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

int main()
{
    srand( (unsigned int)time(0) ); 
    int num = rand()%10+1;
    while (!gameOver)
    {   

        Draw(num);
        Input();
        Logic();
    }

    return 0;
}
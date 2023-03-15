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

bool gameWin=false;
bool gameOver1=false;
int NumberX[6];
int NumberY[6];
int k=0;
int w=0;
int number[6];
int a[3];
int level=0;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

vector<int> nums;
void GenerateLocation(){
    srand(time(0));
    int key=0,j=0; 
        for(int i=0;i<6;i++){
        NumberX[i] = rand()%(width-2)+1; 
        NumberY[i] = rand()%(height-2)+1;
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

void rand_number(int num,int level){

    srand(time(0));
    int key=0,j=0;
    if(level == 1){
        for(int i=0;i<1;i++){
            number[i] = rand()%5+1; 
        }
        number[1] = num-number[0];
        number[2] = num-number[0];
        number[3] = num-number[0];
        number[4] = num-number[0];
        number[5] = num-number[0];
    }else if(level == 1){
        for(int i=0;i<2;i++){
            number[i] = rand()%5+1; 
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
        number[2]=num-number[0];
        number[3]=num-number[0];
        number[4]=num-number[1];
        number[5]=num-number[1];        
    }else if(level == 2){
        for(int i=0;i<2;i++){
            number[i] = rand()%5+1; 
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
        number[2]=num-number[1];
        number[3]=num-number[0];
        number[4]=num-number[1];
        number[5]=num-number[0];        
    }else if(level == 3){
        for(int i=0;i<3;i++){
            number[i] = rand()%5+1; 
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
    }else if(level == 4){
        for(int i=0;i<4;i++){
            number[i] = rand()%5+1; 
            for(int j=0;j<i;j++){
                if(number[i]==number[j]){
                    i--;
                }
            }
        }

        for(int i=0;i<(sizeof(number) / sizeof(int))-2;i++){
            key=number[i];
            j=i-1;
        while(j>=0 && number[j]>key){
            number[j+1]=number[j];
            j-=1;
        }
        number[j+1]=key;
        }
        number[4]=num-number[1];
        number[5]=num-number[2];        
    }else if(level == 5){
        for(int i=0;i<5;i++){
            number[i] = rand()%5+1; 
            for(int j=0;j<i;j++){
                if(number[i]==number[j]){
                    i--;
                }
            }
        }

        for(int i=0;i<(sizeof(number) / sizeof(int))-1;i++){
            key=number[i];
            j=i-1;
        while(j>=0 && number[j]>key){
            number[j+1]=number[j];
            j-=1;
        }
        number[j+1]=key;
        }
        int g = rand()%5;
        number[5]=num-number[g];        
    }

}

void Setup(){
    int num;
    srand(time(NULL));
    gameOver1 = false;
    dir = STOP;
    GenerateLocation();
}

void Draw(int num){
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 10);
    cout << "             SMART Snake Game   \n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "                Number is " <<    num   << "\n";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "^ UP , v down , < LEFT , > RIGHT ,  x to EXIT\n";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "_" << a[0] << "_ + _" << a[2] << "_ " << " = " <<num << "\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout << "               Level " << level << "\n";

    string text[height] ;
    for(int i=0;i<height;i++){
        SetConsoleTextAttribute(hConsole, 240);
        for(int j=0;j<width;j++){
            if(i==0 || i==height-1){
                //cout<<"_";
                text[i]+=  "_";
            }else if(j==0 || j==width-1){
                //cout<<"|";
                text[i]+= "|";
            }else if(i == locationY && j == locationX){
                //cout << "#";
                text[i]+= "#";
            }else{
             if(j == NumberX[k] && i== NumberY[k]){
                    //cout << number[k];
                    text[i]+= to_string(number[k]);
                    //text[i]+= numberic[k];
                    k++;
                }else{ 
                    //cout << " ";
                    text[i]+= " ";
                }
            }
            
            bool foundNum = false;
            for (int k = 0; k < nums.size(); k++){
                if (i == locationY && j == locationX){
                    foundNum = true;
                }
            }
    
        }
        
    }

    for(int i=0;i<height;i++){
                cout << text[i]<<endl;
                //SetConsoleTextAttribute(hConsole, 7);
            }
    SetConsoleTextAttribute(hConsole, 7);
        k=0;
    
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
        case 'x' : gameOver1 = 1;
            break;
        default :
            break;
        }

    }

}

void Logic(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (locationX <= 0 || locationX >= width || locationY <= 0 || locationY >= height){
        cout << "\n";
        SetConsoleTextAttribute(hConsole, 78);
        cout << "____________________\n";
        cout << "                    \n";
        cout << "      You lose      \n";
        cout << "                    \n";
        cout << "____________________\n";
        SetConsoleTextAttribute(hConsole, 7);
        //cout << "  \n";
        gameOver1 = true;
    }else{
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
    }
    
    bool foundNum = false;
    for(int i=0;i<6;i++){
        //for (int k = 0; k < nums.size(); k++){
        if (NumberY[i] == locationY && NumberX[i] == locationX){
    
                a[w]=number[i];
                w++;
                //foundNum = true; 
            }
        //}
    }   
}

void checkAns(int num){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(a[0]!=0 && a[1]!=0){
        if(a[0]+a[1]==num){ 
            cout << "\n";
            SetConsoleTextAttribute(hConsole, 100);
            cout << "____________________\n";
            cout << "                    \n";
            cout << "      You win       \n";
            cout << "                    \n";
            cout << "____________________\n";
            SetConsoleTextAttribute(hConsole, 7);
            //cout << "  \n";
            level+=1;
            gameWin = true;
        }else{
            cout << "\n";
            SetConsoleTextAttribute(hConsole, 78);
            cout << "____________________\n";
            cout << "                    \n";
            cout << "      You lose      \n";
            cout << "                    \n";
            cout << "____________________\n";
            SetConsoleTextAttribute(hConsole, 7);
            //cout << "  \n";
            gameOver1 = true;    
        }
        Sleep(3000);
        
    } 
}

int playsnake(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<int> number = {1, 2, 3};
    // Seed the random number generator with the current time
    srand(time(0));
    //For random number
    int num = rand()%5+6;
    // Generate a random number between 0 and 5
    int rand_num = rand() % 6;
    // Randomize the position of the random number in the vector
    random_shuffle(number.begin(), number.end());

        GenerateLocation();
        rand_number(num,level);

    while (true){
        Draw(num);
        Input();
        Logic();
        checkAns(num);
        if(gameWin){
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(5000);
            break;
        }else if(gameOver1){
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(5000);
            break;
        }
        Sleep(30);
    }


    return 1;
}

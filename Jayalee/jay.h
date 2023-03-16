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


class eatnum{
int locationX = 1, locationY = 1;
public:
bool gameWin = false;
bool gameOver1 = false;
bool gameExit = false;
int NumberX[6];
int NumberY[6];
int k=0;
int w=0;
int number[6];
int a[3]={0,0,0};
int level;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
vector<int> nums;
void GenerateLocation();
void rand_number(int ,int );
void Setup();
void Draw(int ,int );
void Input();
void Logic();
void checkAns(int );
};


void eatnum::GenerateLocation(){
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

void eatnum::rand_number(int num,int level){

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

void eatnum::Setup(){
    int num;
    srand(time(NULL));
    gameOver1 = false;
    dir = STOP;
    GenerateLocation();
}

void eatnum::Draw(int num,int level){
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t             SMART Snake Game   \n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << "\t                Number is " <<    num   << "\n";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t^ UP , v down , < LEFT , > RIGHT ,  x to EXIT\n";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\t_" << a[0] << "_ + _" << a[2] << "_ " << " = " <<num << "\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout << "\t               Level " << level << "\n";

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
                cout << "\t"<<text[i]<<endl;
                //SetConsoleTextAttribute(hConsole, 7);
            }
    SetConsoleTextAttribute(hConsole, 7);
        k=0;
    
}

void eatnum::Input(){

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
        case 'x' : gameExit = true;
            break;
        default :
            break;
        }

    }

}

void eatnum::Logic(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (locationX <= 0 || locationX >= width || locationY <= 0 || locationY >= height){
        dir = STOP;
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

void eatnum::checkAns(int num){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(a[0]!=0 && a[1]!=0){
        if(a[0]+a[1]==num){ 
            cout << "\n";
            //cout << "  \n";
            level+=1;
            dir = STOP;
            gameWin = true;
        }else{
            cout << "\n";
            //cout << "  \n";
            dir = STOP;
            gameOver1 = true;    
        }
        Sleep(3000);
        
    } 
}

int playsnake(int lvl){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<int> number = {1, 2, 3};
    eatnum x;
    // Seed the random number generator with the current time
    srand(time(0));
    //For random number
    int num = rand()%5+6;
    // Generate a random number between 1 and 6
    int rand_num = rand()%5+1;
    // Randomize the position of the random number in the vector
    random_shuffle(number.begin(), number.end());

    x.GenerateLocation();
    x.rand_number(num,lvl);

    while (true){
        x.Draw(num,lvl);
        x.Input();
        x.Logic();
        x.checkAns(num);
        if(x.gameWin){
            SetConsoleTextAttribute(hConsole, 100);
            cout << "\t____________________\n";
            cout << "\t                    \n";
            cout << "\t      You win       \n";
            cout << "\t                    \n";
            cout << "\t____________________\n";
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(1500);
            system("cls");
            return 1;
        }else if(x.gameOver1){
            SetConsoleTextAttribute(hConsole, 78);
            cout << "\t____________________\n";
            cout << "\t                    \n";
            cout << "\t      You lose      \n";
            cout << "\t                    \n";
            cout << "\t____________________\n";
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(1500);
            system("cls");
            return 0;
        }else if(x.gameExit){
            SetConsoleTextAttribute(hConsole, 240);
            cout << "\t____________________\n";
            cout << "\t                    \n";
            cout << "\t      You exit      \n";
            cout << "\t                    \n";
            cout << "\t____________________\n";
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(1500);
            system("cls");
            return 0;
        }
        Sleep(30);
    }
}

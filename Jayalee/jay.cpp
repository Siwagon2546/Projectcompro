#include<iostream>
#include<conio.h>
#include<vector>
#include<windows.h>
#include<ctime>

using namespace std;
void snakecreate(int num){
    int width = 40;
    int height = 20;
    srand(time(0));
    int locationX[5] = {(rand()%(width-1))+1,(rand()%(width-1))+1,(rand()%(width-1))+1,(rand()%(width-1))+1,(rand()%(width-1))+1};
    int locationY[5] = {(rand()%(height-1))+1,(rand()%(height-1))+1,(rand()%(height-1))+1,(rand()%(height-1))+1,(rand()%(height-1))+1};
    //locationX[4] != locationX[3] != locationX[2] != locationX[1] != locationX[0];
    //locationY[4] != locationY[3] != locationY[2] != locationY[1] != locationY[0];
    cout << "          SMART Snake Game   \n";
    cout << "            Number is " <<    num    << "\n";

vector<vector<char>> rectangle(height, vector<char>(width, ' '));



    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
        if(i==0 or i==height-1){
            rectangle[i][j]='_';
            }else{
            if(j==0 or j==width-1){
                rectangle[i][j]='|';
            }
            }
        }
    }

    for(int k = 0 ; k < 5 ; k++){
        for(int i = 0 ; i < height-1 ; i++){
            for(int j = 0 ; j < width-1 ; j++){
                if(locationX[k] == j && locationY[k] == i){
                    rectangle[i][j]='*';
                }
            }
        }
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
        cout << rectangle[i][j];
        }
        cout << endl;
    }
    
}

//void controllsnake(){
    /*
    unsigned int waited_MS=0 , input_wait_MS=10;
    do{
        if(_kbhit()){
            switch(_getch()){
                case '72' : snake.set_face(Snake::UP); break;
                case '80' : snake.set_face(Snake::DOWN); break;
                case '75' : snake.set_face(Snake::LEFT); break;
                case '77' : snake.set_face(Snake::RIGHT); break;
            }
        }
    }
}*/
/*void sumfruit(){

}
void checkAns(){

}
void monitor(){

}*/
int main(){
    srand(time(0));
    int num = rand()%100 + 1;
    while (true){
    system("cls");
    snakecreate(num);       
    }    
        //Sleep(20);
    return 0;
    
}
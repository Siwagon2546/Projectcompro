#include<iostream>
#include<conio.h>
#include<vector>
#include<windows.h>
#include<ctime>

using namespace std;
void snakecreate(){
    int width = 40;
    int height = 20;
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
    }*/
/*
}
void fruitX(){

}
void fruitY(){

}
void sumfruit(){

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
        
        cout << "          SMART snake Game   \n";  
        cout << "            Number is " <<    num    << "\n";
        snakecreate();
        //Sleep(20);
        }
    
}
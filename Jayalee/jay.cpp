#include<iostream>
#include<conio.h>
using namespace std;
void controllsnake(){
    
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

}
void fruitX(){

}
void fruitY(){

}
double sumfruit(){

}
void checkAns(){

}
void monitor(){

}
int main(){
    
}
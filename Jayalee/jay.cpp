#include<iostream>
#include<conio.h>
#include<vector>
#include<windows.h>
#include<ctime>
#include<list>

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

class Snake {
public:
    enum Face { RIGHT = 1, UP = 2, LEFT = 3, DOWN = 4 }; // 4 directions
    int max_x, max_y, is_alive;
    Face face;
    list<int> cells;
    Snake() { is_alive = 1; }
    Snake(int w, int h): max_x(w), max_y(h) { is_alive = 1; }
    bool having(int a_cell) {
        return this->cells.end() != find(cells.begin(), cells.end(), a_cell);
    }
    void set_face(Face f) { if (2 != abs(face - f)) { face = f; } }
    int head() { return this->cells.back(); }
    int next_head() {
        int x = this->head() % max_x, y = this->head() / max_x;
        switch (this->face) { // caculate new head on current face direction
            case RIGHT:  x = max_x-1 <= x ? 0 : x+1; break;
            case LEFT:  x = x <= 0 ? max_x-1 : x-1; break;
            case UP: y = y <= 0 ? max_y-1 : y-1; break;
            case DOWN: y = max_y-1 <= y ? 0 : y+1; break;
            default: break;
        }
        return y * max_x + x;
    }
};
class controllsnake{
    list<int> field, blanks;
    Snake snake;
    int score, food_cell, max_delay_ms;
    void get_input() {    
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
            waited_MS += input_wait_MS;
            Sleep(input_wait_MS); // wait for next keyboard hit
    }while (max_delay_ms > waited_MS);
    }
};
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
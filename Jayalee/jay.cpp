#include<iostream>
#include<conio.h>
#include<vector>
#include<windows.h>
#include<ctime>
#include<list>
#include<algorithm>
using namespace std;
void snakecreate(){
    int width = 40;
    int height = 20;
    srand(time(0));
    int locationX[5] = {(rand()%(width-1))+1,(rand()%(width-1))+1,(rand()%(width-1))+1,(rand()%(width-1))+1,(rand()%(width-1))+1};
    int locationY[5] = {(rand()%(height-1))+1,(rand()%(height-1))+1,(rand()%(height-1))+1,(rand()%(height-1))+1,(rand()%(height-1))+1};
    //locationX[4] != locationX[3] != locationX[2] != locationX[1] != locationX[0];
    if(locationX[0]==locationX[1]){
        locationX[1]==(rand()%(width-1))+1;
    }else if(locationX[0]==locationX[2]){
        locationX[2]==(rand()%(width-1))+1;
    }else if(locationX[0]==locationX[3]){
        locationX[3]==(rand()%(width-1))+1;
    }else if(locationX[0]==locationX[4]){
        locationX[4]==(rand()%(width-1))+1;
    }else if(locationX[1]==locationX[2]){
        locationX[2]==(rand()%(width-1))+1;
    }else if(locationX[1]==locationX[3]){
        locationX[3]==(rand()%(width-1))+1;
    }else if(locationX[1]==locationX[4]){
        locationX[4]==(rand()%(width-1))+1;
    }else if(locationX[2]==locationX[3]){
        locationX[3]==(rand()%(width-1))+1;
    }else if(locationX[2]==locationX[4]){
        locationX[4]==(rand()%(width-1))+1;
    }else if(locationX[3]==locationX[4]){
        locationX[4]==(rand()%(width-1))+1;
    }
    //locationY[4] != locationY[3] != locationY[2] != locationY[1] != locationY[0];
    if(locationY[0]==locationY[1]){ 
        locationY[1]==(rand()%(height-1))+1;
    }else if(locationY[0]==locationY[2]){
        locationY[2]==(rand()%(width-1))+1;
    }else if(locationY[0]==locationY[3]){
        locationY[3]==(rand()%(width-1))+1;
    }else if(locationY[0]==locationY[4]){
        locationY[4]==(rand()%(width-1))+1;
    }else if(locationY[1]==locationY[2]){
        locationY[2]==(rand()%(height-1))+1;
    }else if(locationY[1]==locationY[3]){
        locationY[3]==(rand()%(width-1))+1;
    }else if(locationY[1]==locationY[4]){
        locationY[4]==(rand()%(width-1))+1;
    }else if(locationY[2]==locationY[3]){
        locationY[3]==(rand()%(height-1))+1;
    }else if(locationY[2]==locationY[4]){
        locationY[4]==(rand()%(width-1))+1;
    }else if(locationY[3]==locationY[4]){
        locationY[4]==(rand()%(height-1))+1;
    }


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

    /*for(int k = 0 ; k < 5 ; k++){
        for(int i = 0 ; i < height-1 ; i++){
            for(int j = 0 ; j < width-1 ; j++){
                if(locationX[k] == j && locationY[k] == i){
                    rectangle[i][j]='*';
                }
            }
        }
    }*/
    
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
    unsigned int waited_MS=0 , input_wait_MS=20;
    do{
        if(_kbhit()){
            switch(_getch()){
                /*case 'w' : snake.set_face(Snake::UP); break;
                case 's' : snake.set_face(Snake::DOWN); break;
                case 'a' : snake.set_face(Snake::LEFT); break;
                case 'd' : snake.set_face(Snake::RIGHT); break;
                case 'X': snake.is_alive = 0; break; // Stop Game
                default: break;*/
                case 72 : snake.set_face(Snake::UP); break;
                case 80 : snake.set_face(Snake::DOWN); break;
                case 75 : snake.set_face(Snake::LEFT); break;
                case 77 : snake.set_face(Snake::RIGHT); break;
                case 'X': snake.is_alive = 0; break; // Stop Game
                default: break;
            }
        }
            waited_MS += input_wait_MS;
            Sleep(input_wait_MS); // wait for next keyboard hit
    }while (max_delay_ms > waited_MS);
    }
    void random_food() {
        blanks.clear(); // clear old field on previous calculation
        int i = 0;
        do { if (!snake.having(i)) { blanks.push_back(i); } }
	while (i++ < field.size()); // Finish finding blank cells
        list<int>::iterator it = blanks.begin(); // iterator at beginning
        advance(it, rand() % blanks.size()); // Go to a random blank cell
        food_cell = *(it); // assign new food position
    }
    void snakeGO() {
        int next_head = snake.next_head();
        if (snake.having(next_head)) { snake.is_alive = 0; } // die on collision
        else { // if there's a food, keep the tail, else cut tail
            if (next_head == food_cell) {
                random_food(); score++; // make new food & increase score
            } else { snake.cells.erase(snake.cells.begin()); }
            snake.cells.push_back(next_head); // move ahead
        }
    }
    void snakebody(){
        srand(time(0));
        int num = rand()%100 + 1;
        cout << "            SMART Snake Game   \n";
        cout << "               Number is " <<    num   << "\n";
            system("cls");
            int field_cell = 0 , width = snake.max_x , height = snake.max_y;

            do {
                
                if (field_cell % width == 0) { cout << "|"; }           //Border
                cout << ( field_cell == food_cell    ? "*" :
                        snake.head() == field_cell ? "0" :
                        snake.having(field_cell)   ? "o" : " " ); // .cout
                if (++field_cell % width == 0) { cout << "|" << endl; }  //Border
                
            } while (field_cell < field.size());
    }
    public:
    controllsnake (Snake s) {
        snake = s;
        int shape = snake.max_x * snake.max_y;
        while (shape) { field.push_back(shape--); } // Make field: 0...shape
    }
    void setup(int delay_ms) {
        srand( (unsigned int)time(0) ); // Randomize the seed
    	snake.cells.push_back(0); snake.cells.push_back(1); // 2 init cells
    	snake.face = Snake::RIGHT; // init face for cells [0,1]
        max_delay_ms = delay_ms;
        random_food();
    }
    void loop() {
        while (snake.is_alive) { get_input(); snakeGO(); snakebody(); }
    };
};

/*void sumfruit(){

}
void checkAns(){

}
void monitor(){

}*/
int main(int argc, const char * argv[]) {
    controllsnake game(Snake(40,20));
    game.setup(100); // Delay 100ms
    game.loop();
    getch(); // press any key to continue
    while (true){
    system("cls");
    snakecreate();       
    }    
        //Sleep(20);
    return 0;
    
}
#include "fluidsortingHeader.h"

int main(){
    srand(time(0));
    fluidsort game;
    game.levelparameter(4);
    cout << game.Nbottle << " + " << game.Nemtybottle << "\t" << game.Nfluidtype << endl << endl ;
    game.createbottle();
    cout << endl << endl;
    game.fillbottle();
    
}
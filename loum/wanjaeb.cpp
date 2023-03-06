#include "Hangman_main.h"      
#include "fluidsortingheader.h"

int main(){
    cout << "Hangman[h] or sorting[s]";
    char choose;
    cin >> choose;
    switch(choose){
        case 'h':
            HangManPlay(1);
            break;
        case 's':
            playFluidsort(1);
            break;
        default :
            cout << "bye";
    }
}
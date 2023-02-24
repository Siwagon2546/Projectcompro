#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std ;

class fluidsort{
    public:
    int Nbotlle;
    int Nemtybottle;
    int Nfluidtype;

    void levelparameter(int); //get Nbottle,Nemtybottle,Nfluidtype form input(lvl of stage)
    void createstage(fluidsort ,fluidsort ,fluidsort);
};

void fluidsort::levelparameter(int stagelvl){
    switch(stagelvl){
        case 1 :
            Nbotlle = 2;
            Nemtybottle = 1;
            Nfluidtype = 2 ;
            break;
        case 2 :
            Nbotlle = 3;
            Nemtybottle = 2;
            Nfluidtype = 3 ;
            break;
    }
}

/*void fluidsort::createstage(fluidsort Nbotlle){

}*/

void test(){
    cout << "test " ;
    Sleep(1000); //Delay (ms)
    system("cls"); //Screenclear
}



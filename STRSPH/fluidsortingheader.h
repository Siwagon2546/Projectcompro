#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std ;

class fluidsort{
    public:
    int Nbottle;
    int Nemtybottle;
    int Nfluidtype;

    void levelparameter(int); //get Nbottle,Nemtybottle,Nfluidtype form input(lvl of stage)
    void createstage();
    void createbottle();
};

void fluidsort::levelparameter(int stagelvl){
    switch(stagelvl){
        case 1 :
            Nbottle = 2;
            Nemtybottle = 1;
            Nfluidtype = 2 ;
            break;
        case 2 :
            Nbottle = 3;
            Nemtybottle = 2;
            Nfluidtype = 3 ;
            break;
    }
}

void fluidsort::createbottle(){
    int bottle[Nbottle + Nemtybottle][Nfluidtype] ;
    for(int i=0;i<Nbottle + Nemtybottle;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            bottle[i][j] =0;
        }
    }

    for(int i=0;i<Nbottle + Nemtybottle;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            if(i !=0 && j ==0){cout << endl;}
            cout << bottle[i][j] << "\t";
            
        }
    }
} 

void fluidsort::createstage(){
    cout<< " ";
}

void test(){
    cout << "test " ;
    Sleep(1000); //Delay (ms)
    system("cls"); //Screenclear
}



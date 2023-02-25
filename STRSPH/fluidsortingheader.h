#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std ;

class fluidsort{
    public:
    int Nbottle;
    int Nemtybottle;
    int Nfluidtype;
    vector<int> bottle;
    vector<vector<int>> bottle2dvector;

    void levelparameter(int); //get Nbottle,Nemtybottle,Nfluidtype form input(lvl of stage)
    void createandfillbottle(); //create array (row = Nbottle , col = Nfluditype) and fillbottle randomly
    void createstage();
    void vector22dvector();
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
        case 3 :
            Nbottle = 4;
            Nemtybottle = 2;
            Nfluidtype = 3 ;
            break;
        case 4 :
            Nbottle = 4;
            Nemtybottle = 2;
            Nfluidtype = 4 ;
            break;
    }
}

void fluidsort::createandfillbottle(){
    for(int i=1;i<Nbottle+1;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            bottle.push_back(i);
        } }
    for(int i=0;i<Nemtybottle*Nfluidtype;i+=1){
        bottle.push_back(0);
    }

    random_shuffle(bottle.begin(),bottle.end());

    for(int i=0;i<(Nbottle + Nemtybottle)*Nfluidtype;i+=1){
        if(i !=0 && i%Nfluidtype==0){cout << endl;}
            cout << bottle[i] << "\t";
    }
}

void fluidsort::vector22dvector(){
    /*
    for(int i=0;i<(Nbottle + Nemtybottle)*Nfluidtype;i=+1){
        bottle2dvector[i/Nfluidtype][i%Nfluidtype] = bottle[i];    //อันนี้ใช้ไม่ได้เฉย
    }*/
    bottle2dvector.resize(Nbottle+Nemtybottle ,bottle);
    
    int k =0;
    for(int i=0;i<Nbottle + Nemtybottle;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            bottle2dvector[i][j] = bottle[k];
            k+=1;
        }
    }

    for(int i=0;i<Nbottle + Nemtybottle;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            cout << bottle2dvector[i][j] << "\t" ;
        }
        cout << endl;
    }
}

void fluidsort::createstage(){
     //Sleep(1000); //Delay (ms)
    //system("cls"); //Screenclear
    cout<< " ";
}

void test(int lvl){
    srand(time(0));
    fluidsort game;
    game.levelparameter(lvl);
    cout << game.Nbottle << " + " << game.Nemtybottle << "\t" << game.Nfluidtype << endl << endl ;
    game.createandfillbottle();
    cout << endl<<endl;
    game.vector22dvector();
}



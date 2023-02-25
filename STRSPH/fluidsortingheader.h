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
    vector<int> type;

    void levelparameter(int); //get Nbottle,Nemtybottle,Nfluidtype form input(lvl of stage)
    void createbottle(); //create array (row = Nbottle , col = Nfluditype)
    void fillbottle();
    void createstage();
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

void fluidsort::createbottle(){
    for(int i=0;i<(Nbottle + Nemtybottle)*Nfluidtype;i+=1){
        bottle.push_back(0);
    }

    for(int i=0;i<(Nbottle + Nemtybottle)*Nfluidtype;i+=1){
            if(i !=0 && i%Nfluidtype==0){cout << endl;}
            cout << bottle[i] << "\t";
    }
}

void fluidsort::fillbottle(){
    for(int i=1;i<Nbottle+1;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            type.push_back(i);
        } }
    for(int i=0;i<Nemtybottle*Nfluidtype;i+=1){
        type.push_back(0);
    }
    
    random_shuffle(type.begin(),type.end());

    for(int i=0;i<(Nbottle + Nemtybottle)*Nfluidtype;i+=1){
        if(i !=0 && i%Nfluidtype==0){cout << endl;}
            cout << type[i] << "\t";
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



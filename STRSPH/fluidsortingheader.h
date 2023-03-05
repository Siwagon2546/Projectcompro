#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> //system cls //color
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> //shuffle

using namespace std ;

class fluidsort{
    public:
    int Nbottle;
    int Nemtybottle;
    int Nfluidtype;
    int select;
    int destination;
    bool win=false;
    vector<int> bottle;
    vector<vector<int>> bottle2dvector;
    vector<bool> sorted;

    void levelparameter(int); //get Nbottle,Nemtybottle,Nfluidtype form input(lvl of stage)
    void createandfillbottle(); //create array (row = Nbottle , col = Nfluditype) and fillbottle randomly
    void vector22dvector(); //converse to 2D vector
    void gravity(); //put 0 to the end
    void showstage();
    void showselect();
    void tranfer();
    void sortcheck();
    void wincheck();
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

    for(int i=0l;i<Nbottle+Nemtybottle;i+=1){
        sorted.push_back(false);
    }

    random_shuffle(bottle.begin(),bottle.end());

    /*for(int i=0;i<(Nbottle + Nemtybottle)*Nfluidtype;i+=1){
        if(i !=0 && i%Nfluidtype==0){cout << endl;}
            cout << bottle[i] << "\t";
    }*/
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

    /*for(int i=0;i<Nbottle + Nemtybottle;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            cout << bottle2dvector[i][j] << "\t" ;
        }
        cout << endl << endl;
    }*/
}

void fluidsort::gravity(){
    int temp;
    for(int k=0;k<Nfluidtype-1;k+=1){
        for(int i=0;i<Nbottle + Nemtybottle;i+=1){
            for(int j=0;j<Nfluidtype-1;j+=1){
                if(bottle2dvector[i][j] == 0){
                    bottle2dvector[i][j] = bottle2dvector[i][j+1];
                    bottle2dvector[i][j+1] = 0;
                }
            }
        }
    }

    /*for(int i=0;i<Nbottle + Nemtybottle;i+=1){
        for(int j=0;j<Nfluidtype;j+=1){
            cout << bottle2dvector[i][j] << "\t" ;
        }
        cout << endl;
    }*/
}

void fluidsort::showstage(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl << endl;
    for(int i=0;i<Nbottle+Nemtybottle;i+=1){ //cap
        //cout << "\t" << "-=-" ;
        switch(sorted[i]){
            case false:
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\t" << ".  ." ;
                break;
            case true:
                cout << "\t" << "." ;
                SetConsoleTextAttribute(hConsole, 6);
                cout << "==";
                SetConsoleTextAttribute(hConsole, 15);
                cout << ".";
                break;
        }
    }
    cout << endl;
    for(int i =Nfluidtype-1;i>=0;i-=1){   //in
        for(int j=0;j<Nbottle + Nemtybottle;j+=1){
            //cout << "\t" <<"|"<< bottle2dvector[j][i]<<"|" ;
            switch(bottle2dvector[j][i]){
                case 0:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 15);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 1:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 144);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 2:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 160);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 3:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 192);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 4:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 208);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 5:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 240);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 6:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 96);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 7:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 48);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
                case 8:
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "\t" <<"|";
                    SetConsoleTextAttribute(hConsole, 8);
                    //cout << "  ";
                    cout << " " << bottle2dvector[j][i] << " ";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout <<"|";
                    break;
            }
        }
        cout << endl;
    }
    for(int i=0;i<Nbottle+Nemtybottle;i+=1){  //bottom
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\t" << "====" ;
    }
    cout << endl << endl ;
}

void fluidsort::showselect(){ //showstage + tranfer
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    do{
        system("cls");
        for(int i=0;i<6;i+=1){
            cout << sorted[i];
        }
        showstage();
        for(int i=0;i<Nbottle+Nemtybottle;i+=1){
            cout << "\t"<< "[" << i+1 << "] "; //print selected
        }
        cout << endl << endl << "Tranfer" << " [SELECT :"; //select
        for(int i=0;i<Nbottle+Nemtybottle;i+=1){
            cout << " " << i+1 ;
        }
        cout << "]";
        cin >> select;
    }while((select <= 0 || select > Nbottle+Nemtybottle) || (sorted[select-1]==true) );

    do{
        system("cls");
        for(int i=0;i<6;i+=1){
            cout << sorted[i];
        }
        showstage();
        for(int i=0;i<Nbottle+Nemtybottle;i+=1){ //print selected
            //cout << "\t"<< "[" << i+1 << "]"; 
            if(select-1 == i){
                SetConsoleTextAttribute(hConsole, 10);
                cout << "\t"<< "[" << i+1 << "]";
                SetConsoleTextAttribute(hConsole, 15);
            }else cout << "\t"<< "[" << i+1 << "]"; 
        }
        cout << endl << endl << "Tranfer " << select << " to " << "[SELECT :";
        for(int i=0;i<Nbottle+Nemtybottle;i+=1){
            if(i!=select-1){cout << " "<< i+1;}
        }
        cout << "]";
        cin >> destination;
    }while((destination <=0 || destination > Nbottle+Nemtybottle || destination ==select) || (sorted[select-1]==true));
    
    select-=1;
    destination-=1;
    //cout << select << destination;
}

void fluidsort::tranfer(){
    int posselect,colorselect,posdest,colordest;

    for(int k=0;k<Nfluidtype;k+=1){
        for(int i=Nfluidtype-1;i>=0;i-=1){
            if(bottle2dvector[select][i]!=0){
                //cout << i << bottle2dvector[select][i];
                posselect = i;
                colorselect = bottle2dvector[select][i];
                break;
            }
        }

        for(int i=Nfluidtype-1;i>=0;i-=1){
            if(bottle2dvector[destination][i]!=0){
                //cout << i<<bottle2dvector[destination][i];
                posdest = i;
                colordest = bottle2dvector[destination][i];
                break;
            }
        }

        if((colordest == colorselect && bottle2dvector[destination][Nfluidtype-1]==0) || bottle2dvector[destination][0]==0){
            bottle2dvector[destination][Nfluidtype-1] = bottle2dvector[select][posselect];
            bottle2dvector[select][posselect] = 0;
        }
        gravity();
    }
}

void fluidsort::sortcheck(){
    for(int i=0;i<Nbottle+Nemtybottle;i+=1){
        double sum=0;
        for(int j=0;j<Nfluidtype;j+=1){
            sum+=bottle2dvector[i][j];
        }
        if(((sum/Nfluidtype)==bottle2dvector[i][0]) && bottle2dvector[i][Nfluidtype-1]!=0){
            sorted[i]=true;
        }else sorted[i]=false;
    }
}

void fluidsort::wincheck(){
    
}

void test(int lvl){
    //Sleep(1000); //Delay (ms)
    //system("cls"); //Screenclear
    srand(time(0));
    fluidsort game;
    game.levelparameter(lvl);
    //cout << game.Nbottle << " + " << game.Nemtybottle << "\t" << game.Nfluidtype << endl << endl ;
    game.createandfillbottle();
    game.vector22dvector();
    game.gravity();
    //game.showselect();
    //cout << game.select << game.destination;
    while(!game.win){
        game.showselect();
        game.tranfer();
        game.sortcheck();
        //game.wincheck();
    }
}

//wincheck
//sorted =1   --->  select gone
//move 2 to 1  disable
//gecht()
//exit


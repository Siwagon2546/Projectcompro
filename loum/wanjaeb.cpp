#include "Hangman_main.h"      
#include "fluidsortingheader.h"

#include <fstream>
#include <string>

class PLAY{
    public:
    string filesavename = "waanjaeb.txt";
    int select;
    bool nouser = true;
    string name;
    int score;
    //int startselect;
    vector<int> scorevector;
    vector<string> namevector;

    void fileread();
    void gamestart();
    void userselect();
    void createuser();
    void startmenu();
    //void scoreboard();
};

fstream FileSave;

void PLAY::fileread(){
    FileSave.open(filesavename);
    string text;
    char name[100];
    int score;
    for(int i=0;getline(FileSave,text);i+=1){
        if(text !=""){
        sscanf(text.c_str(),"%[^:]:%d",name,&score);
        scorevector.push_back(score);
        namevector.push_back(name);
        nouser = false;
        }
    } 
    FileSave.close();
    /*for(int i=0;i<scorevector.size();i+=1){
        cout << scorevector[i] << " " << namevector[i] << endl;
    }*/
}

void PLAY::gamestart(){
    system("cls");
    cout << endl << endl << "WAAN JAEB ARCADE GAME";
    cout << endl << endl << endl << endl << "Press any key to continue";
    getch();
}

void PLAY::userselect(){
    system("cls");
    cout << "      Please select user"<< endl;
    if(nouser !=true){
    for(int i=0;i<namevector.size();i+=1){
        cout << "\t[" << i+1 << "] " << namevector[i] << endl; 
        //cout << namevector.size();
    }}else{cout << "\t   Please create new user";}
    cout << endl;
    cout << "\t" << "[0]" << " Create new user" << endl;
    cout << "\t" << "[/]" << " Delete user" << endl;
    cout << "\t" << "[ESC]" << " EXIT" << endl ;
    //cout << usercount;
    int input;
    do{
    input = getch();
    switch(input){
        case 27:
            system("cls");
        cout << endl << endl <<"\tEXIT" ;
        Sleep(1500);
        system("cls");
        exit(0);
            break;
        case '1':
            select = 1;
            break;
        case '2':
            select = 2;
            break;
        case '3':
            select = 3;
            break;
        case '4':
            select = 4;
            break;
        case '5':
            select = 5;
            break;
        case '6':
            select = 6;
            break;
        case '7':
            select = 7;
            break;
        case '8':      
            select = 8;
            break;
        case '9':
            select = 9;
            break;
        case '0':
            select = 0;
            break;
        case '/':
            select = 1;
            break;
        default:
            break;
    }
    }while((input <47 || input >57 )  ||  (select > namevector.size()));
    if(input ==47){
        select =-1;
    }
}

void PLAY::createuser(){
    if(select ==0 && namevector.size() <9){
    system("cls");
    cout << "      Please enter your name" << endl;
    
    string text;
    vector<bool> creatable;
    getline(cin,text);
    //cout << text;
    for(int i=0;i<namevector.size();i+=1){
        if(text==namevector[i]){
            creatable.push_back(false);
            cout << "      cannot create " << text;
            Sleep(1500);
            break;
        }else creatable.push_back(true);
    }

    bool creatable2=true;

    for(int i=0;i<creatable.size();i+=1){
        if(creatable[i] == false){
            creatable2 = false;
        }
    }

    if(creatable2){
        namevector.push_back(text);
        scorevector.push_back(0);
        system("cls");
        cout << "      " << text << " has been create";
        //cout << namevector.size();
        Sleep(1500);
    }else if(select ==0 && namevector.size() >=9){
        system("cls");
        cout << "      cannot create ";
        //cout << namevector.size();
        Sleep(1500);
    }
    
    FileSave.open(filesavename);
    for(int i=0;i<namevector.size();i+=1){
        FileSave << namevector[i] <<":"<<scorevector[i]<<endl;
    }
    FileSave.close();

    }else if(select ==0 && namevector.size() >=9){
    system("cls");
    cout << "      cannot create ";
    Sleep(1500);
    }

    if(select == -1){       //delete
        system("cls");
        cout << "      Select to delete" << endl;
        for(int i=0;i<namevector.size();i+=1){
        cout << "\t[" << i+1 << "] " << namevector[i] << endl; 
        }
        cout << endl << "\t" << "[ESC]" << " EXIT" << endl ;

        int input;
        bool loop = true;
        int selectdel;
    do{
    input = getch();
    switch(input){
        case 27:
            system("cls");
            cout << endl << endl <<"\tEXIT" ;
            Sleep(1500);
            system("cls");
            selectdel = 1;
            loop = false;
            break;
        case '1':
            selectdel = 1;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '2':
            selectdel = 2;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '3':
            selectdel = 3;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '4':
            selectdel = 4;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '5':
            selectdel = 5;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '6':
            selectdel = 6;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '7':
            selectdel = 7;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '8':      
            selectdel = 8;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        case '9':
            selectdel = 9;
            //namevector.erase(namevector.begin()+selectdel-1);
            //scorevector.erase(scorevector.begin()+selectdel-1);
            //loop = false ;
            break;
        default:
            break;
    }
    
    if(input ==27){
        loop= false;
    }else loop = ((input <48 || input >57 )  ||  (selectdel > namevector.size()));
    }while( loop );

    if(input!=27){
    int temp = namevector.size();
    namevector.erase(namevector.begin()+selectdel-1);
    scorevector.erase(scorevector.begin()+selectdel-1);
    }

    /*for(int i =0;i<namevector.size();i+=1){
        cout << namevector[i] << endl;
    }*/
    //cout << namevector.size()<< "size";

    FileSave.open(filesavename);
    for(int i=0;i<namevector.size();i+=1){
        FileSave << namevector[i] <<":"<<scorevector[i]<<endl;
    }
    for(int i=0;i<10;i+=1){
        FileSave << "" << endl;
    }
    FileSave.close();
    //cout << "asdsadasd";
}
}



/*void PLAY::scoreboard(){ //ต้องทำให้เรียงมากไปน้อย
    char sname[100];
    int sscore;
    string text;
    FileSave.open(filesavename);
    for(int i=0;getline(FileSave,text);i+=1){
        sscanf(text.c_str(),"%[^:]:%d",sname,&sscore);
        cout << "\t" << "-" << i+1 << "- " << sname << "      "<< sscore << endl;
    }
    FileSave.close();
}*/

void PLAY::startmenu(){
    system("cls");
    name = namevector[select-1];
    score = scorevector[select-1];

    cout << "ID : " << name << "      your score = "<< score <<endl << endl;
    cout << "      WAAN JAEB ARCADE GAME" << endl ;
    cout << "\t[1]"<< " FluidSort" << endl ;
    cout << "\t[2]"<< " Maze" << endl ;
    cout << "\t[3]"<< " Hangman" << endl ;
    cout << "\t[4]"<< " NumberSort" << endl ;
    cout << "\t[5]"<< " Eating" << endl << endl;
    cout << "\t[S]"<< " Select Username" << endl;
    cout << "\t[B]"<< " ScoreBoard" << endl;
    cout << "\t[Esc]"<< " EXIT" << endl;

    /*switch(getch()){
        case 27:
            system("cls");
            cout << endl << endl <<"\tEXIT" ;
            Sleep(1500);
            system("cls");
            exit(0);
            break;
        case 66:
        case 98:
            startselect = 7;
            break;
        case 83:
        case 115:
            startselect = 6;
            break;
        case 49:
            startselect = 1;
            break;
        case 50:
            startselect = 2;
            break;
        case 51:
            startselect = 3;
            break;
        case 52:
            startselect = 4;
            break;
        case 53:
            startselect = 5;
            break;
    }*/
}

int main(){
    PLAY play;
    /*
    do{
    play.userselect();
    while(play.select ==0){
    break;
    }

    do{
    play.startmenu();
    

    }while((play.startselect !=6));

    }while((play.startselect==6));*/
    play.fileread();
    play.gamestart();
    play.userselect();
    play.createuser();
    
    play.startmenu();
    
}


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
    bool playable = false; 
    int score;
    bool SBviwe = false;
    vector<int> scorevector;
    vector<string> namevector;
    int FSlvl;
    int MZlVl;
    int HMlvl;
    int SNlvl;
    int NPlvl;

    void fileread();
    void gamestart();
    void userselect();
    void createuser();
    void startmenu();
    void scoreboard();
    void leveled();
    //ใส่สี
    //เพิ่มเกม
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
    //cout << "\t" << "[ESC]" << " EXIT" << endl ;
    //cout << usercount;
    int input;
    do{
    input = getch();
    switch(input){
        /*case 27:
            system("cls");
        cout << endl << endl <<"\tEXIT" ;
        Sleep(1500);
        system("cls");
        exit(0);
            break;*/
        case '1':
            select = 1;
            playable = true;
            break;
        case '2':
            select = 2;
            playable = true;
            break;
        case '3':
            select = 3;
            playable = true;
            break;
        case '4':
            select = 4;
            playable = true;
            break;
        case '5':
            select = 5;
            playable = true;
            break;
        case '6':
            select = 6;
            playable = true;
            break;
        case '7':
            select = 7;
            playable = true;
            break;
        case '8':      
            select = 8;
            playable = true;
            break;
        case '9':
            select = 9;
            playable = true;
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
        cout << endl << "\t" << "[ESC]" << " BACK" << endl ;

        int input;
        bool loop = true;
        int selectdel;
    do{
    input = getch();
    switch(input){
        case 27:
            system("cls");
            cout << endl << endl <<"\tBACK" ;
            Sleep(1500);
            system("cls");
            selectdel = 1;
            loop = false;
            break;
        case '1':
            selectdel = 1;
            break;
        case '2':
            selectdel = 2;
            break;
        case '3':
            selectdel = 3;
            break;
        case '4':
            selectdel = 4;
            break;
        case '5':
            selectdel = 5;
            break;
        case '6':
            selectdel = 6;
            break;
        case '7':
            selectdel = 7;
            break;
        case '8':      
            selectdel = 8;
            break;
        case '9':
            selectdel = 9;
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
    system("cls");
    cout << "      " << namevector[selectdel-1] << " has been delete";
    Sleep(1500);
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



void PLAY::scoreboard(){ //ต้องทำให้เรียงมากไปน้อย
    vector<int> sortscore;
    for(int i=0;i<scorevector.size();i+=1){
        sortscore.push_back(scorevector[i]);
    }
    
    vector<int> sortpos;
    int max ;
    int maxpos;
    for(int k=0;k<sortscore.size();k+=1){
        max = 0;
        maxpos =0;
    for(int i=0;i<sortscore.size();i+=1){
        if(max <= sortscore[i]){
            max = sortscore[i];
            maxpos = i;
        }
    }
    sortscore[maxpos] = -10;
    sortpos.push_back(maxpos);
    /* for(int h=0;h<scorevector.size();h+=1){
        cout << sortscore[h] << " " ;
    } */
    //cout << endl;
    }
    
    
    /*  for(int i=0;i<sortpos.size();i+=1){
        cout << sortpos[i] << " " ;
    }  */
    int input;
    if(SBviwe == true){
    do{
    system("cls");
    cout << "      ScoreBoard" << endl;
    
    for(int i=0;i<sortpos.size();i+=1){
        cout << "\t-" << i+1 << "- " << namevector[sortpos[i]] << setw(20) << "\t"<< scorevector[sortpos[i]] << endl;
    }
    cout << endl << "\t[ESC] back";

    input = getch();
    }while(input !=27);
    SBviwe = false;
    
    }
    
    

}

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
    cout << "\t[0]"<< " Select Username" << endl;
    cout << "\t[/]"<< " ScoreBoard" << endl;
    cout << "\t[Esc]"<< " EXIT AND SAVE" << endl;
    //cout << "\t" << FSlvl << endl;

    int input;
    do{
    input = getch();
    switch(input){
        case 27:
            system("cls");
            cout << endl << endl <<"\tEXIT AND SAVE" ;
            Sleep(1500);
            FileSave.open(filesavename);
        for(int i=0;i<namevector.size();i+=1){
            FileSave << namevector[i] <<":"<<scorevector[i]<<endl;
        }
        FileSave.close();
            system("cls");
            exit(0);
            break;
        case 47:
            SBviwe = true;
            break;
        case 48:
            playable = false;
            break;
        case 49:
            scorevector[select-1]+=playFluidsort(FSlvl);
            break;
        case 50:
            //startselect = 2;
            break;
        case 51:
            //startselect = 3;
            break;
        case 52:
            //startselect = 4;
            break;
        case 53:
            //startselect = 5;
            break;
    }
    }while(input <47 || input>53);

}

void PLAY::leveled(){
    if(scorevector[select-1] <2){
        FSlvl = 1;
    }else if(scorevector[select-1] < 5){
        FSlvl = 2;
    }else if(scorevector[select-1] < 7){
        FSlvl = 3;
    }else if(scorevector[select-1] < 9){
        FSlvl = 4;
    }else if(scorevector[select-1] < 12){
        FSlvl = 5;
    }else if(scorevector[select-1] < 15){
        FSlvl = 6;
    }else if(scorevector[select-1] < 18){
        FSlvl = 7;
    }else if(scorevector[select-1] < 21){
        FSlvl = 8;
    }else if(scorevector[select-1] < 26){
        FSlvl = 9;
    }else if(scorevector[select-1] < 31){
        FSlvl = 10;
    }else if(scorevector[select-1] < 36){
        FSlvl = 11;
    }else FSlvl = 12;


}

int main(){
    PLAY play;

    play.fileread();
    play.gamestart();

while(true){
while(!play.playable){
    play.userselect();
    play.createuser();
}
while(play.playable){
    play.leveled();
    play.startmenu();
    play.scoreboard();
}
}
    
}


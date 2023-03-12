#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h> // Color Library //
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;

void HangManCreate(int tries){

    cout << endl << endl;
    cout << "   -----" << endl;
    cout << "   |   |" << endl;
    cout << "   |"; if(tries >= 1) cout << "   O   "; cout << endl;
    cout << "   |"; if(tries >= 2) cout << "  /"; 
                    if(tries >= 3) cout << "|";
                    if(tries >= 4) cout << "\\"; cout << endl;
    cout << "   |"; if(tries >= 5) cout << "  /";
                    if(tries >= 6) cout << " \\"; cout << endl;
    cout << "   |" << endl;
    cout << "  _|_" << endl;
	cout << "     " << endl;
	cout << "     " << endl;
}

void importWord(int lv, vector<string> &x){  //x = word lmao

	if(lv == 1){
		ifstream word;
    	word.open("word/lv1.txt");
		string textline;
		string A;
		char word_1[100];

		while(getline(word,textline)){
			sscanf(textline.c_str(),"%s",word_1);
			A = word_1;
			x.push_back(A);
		}
    }

	if(lv == 2){
		ifstream word;
    	word.open("word/lv2.txt");
		string textline;
		string A;
		char word_1[100];

		while(getline(word,textline)){
			sscanf(textline.c_str(),"%s",word_1);
			A = word_1;
			x.push_back(A);
		}
    }

	if(lv == 3){
		ifstream word;
    	word.open("word/lv3.txt");
		string textline;
		string A;
		char word_1[100];

		while(getline(word,textline)){
			sscanf(textline.c_str(),"%s",word_1);
			A = word_1;
			x.push_back(A);
		}
    }

	if(lv == 4){
		ifstream word;
    	word.open("word/lv4.txt");
		string textline;
		string A;
		char word_1[100];

		while(getline(word,textline)){
			sscanf(textline.c_str(),"%s",word_1);
			A = word_1;
			x.push_back(A);
		}
    }

	if(lv == 5){
		ifstream word;
    	word.open("word/lv5.txt");
		string textline;
		string A;
		char word_1[100];

		while(getline(word,textline)){
			sscanf(textline.c_str(),"%s",word_1);
			A = word_1;
			x.push_back(A);
		}
    }

	if(lv == 6){
		ifstream word;
    	word.open("word/Unlimit.txt");
		string textline;
		string A;
		char word_1[100];

		while(getline(word,textline)){
			sscanf(textline.c_str(),"%s",word_1);
			A = word_1;
			x.push_back(A);
		}
    }
	
}

string Lowercase(const string& word){
	int num = word.length();
	string lowerWord = "";

	for (int i = 0; i < word.length(); i++) {
        lowerWord += tolower(word[i]);
    }

	return lowerWord;
}

void HintWord(const string& word, int lv) {
    srand(time(nullptr));
    int letterNum1 = rand() % word.length();
	int letterNum2 = rand() % word.length();
	while(letterNum2 == letterNum1) letterNum2 = rand() % word.length();

	string wordHint1;
	string wordHint2;

	if(word.length() < 5){
		wordHint1 = word[letterNum1];
		cout << Lowercase(wordHint1);
	}else if(lv >= 5){
		wordHint1 = word[letterNum1];
		wordHint2 = word[letterNum2];
		cout << Lowercase(wordHint1) << " " << Lowercase(wordHint2);
	}

}

int HangManPlay(int lv){

	srand (time(nullptr));

	HANDLE Text_Color = GetStdHandle(STD_OUTPUT_HANDLE); // Set for text-color //
		SetConsoleTextAttribute(Text_Color,15);

	vector<string> wordList;
	string word;
	string guessed;
	
	importWord(lv,wordList);
	if(lv <= 5) word = wordList[rand()%499];
	else if(lv == 6) word = wordList[rand()%2217];

	word = Lowercase(word);

	int wordLength = word.length();
	string dispWord (wordLength, '_');


	
	int found = 0;
	char guess = ' ';
	int tries = 0;
	int flagFound = 0;
    int WRONGTRIES = 6;
	bool Exit = false;

	while(tries>=0){

		system("cls");

		cout << "\tLevel : " << lv << endl;

		if(lv > 3){
			cout << "\tHint : ";
			HintWord(word,lv); 
			cout << endl << endl;
		}

		cout << "Guess The Word: " << endl << endl;
		 
		for(int i = 0; i < wordLength; i++)
			cout << " " << dispWord[i] << " "; 
		cout << endl << endl << endl;
		 	
			SetConsoleTextAttribute(Text_Color,4);
		cout << "Wrong Attempts: " << tries << " / " << WRONGTRIES << endl;
			SetConsoleTextAttribute(Text_Color,15);
		cout << "Guessed Letters: " << guessed << endl; 

			SetConsoleTextAttribute(Text_Color,1);
		HangManCreate(tries);
			SetConsoleTextAttribute(Text_Color,15);
		
		if( found == wordLength ){
			SetConsoleTextAttribute(Text_Color,1);
			cout << endl;
			cout << "******************" << endl;
			cout << "*     You Win    *" << endl;
			cout << "* Bro So Good XD *" << endl;
			cout << "******************" << endl;

			SetConsoleTextAttribute(Text_Color,15);
			cout << " Answer : " << word << endl;
			Sleep(1500);

			return 1;
			break;
		}
		
		if(tries == 6) break; 
		
		cout<<"Pick a Letter:";
		guess = getche();
		guess = tolower(guess);

		if(guess == 27){
			system("cls");
            cout << endl << endl <<"\tEXIT" ;
            Sleep(1500);
            system("cls");
			Exit = true;
            break;
		}
		
		guessed = guessed + " " + guess;
		guessed = Lowercase(guessed);
		
		if( dispWord.find(guess) != string::npos ) tries++;
		
		flagFound = 0;
		for(int i=0; i<wordLength; i++){
			if( word[i]==guess && dispWord[i]=='_' ){
				dispWord[i] = guess;
				found++;
				flagFound = 1; 
			}
		}
		 
		if( !flagFound )
			tries++;
	}

	while(Exit == false){

		if(Exit == true){
        	break;
    	}

		if( found != wordLength ){
			SetConsoleTextAttribute(Text_Color,4);
			cout << endl;
			cout << "******************" << endl;
			cout << "*    You Lose    *" << endl;
			cout << "* GGEZ Noob Shit *" << endl;
			cout << "******************" << endl;

			SetConsoleTextAttribute(Text_Color,15);
			cout << " Answer : " << word << endl;
			Sleep(1500);

			return 0;
		}
	}

}
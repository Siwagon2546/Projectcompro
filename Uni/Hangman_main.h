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
#include <time.h>

using namespace std;

void HangManCreate(int tries){

	HANDLE Text_Color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << endl;
	SetConsoleTextAttribute(Text_Color,145);
	for(int i = 0; i < 50;i++){
		cout << "-";
 	}
	SetConsoleTextAttribute(Text_Color,15);

    cout << endl << endl;
    cout << "\t\t    -----" << endl;
    cout << "\t\t    |   |" << endl;
    cout << "\t\t    |"; if(tries >= 1) cout << "   O   "; cout << endl;
    cout << "\t\t    |"; if(tries >= 2) cout << "  /"; 
                    if(tries >= 3) cout << "|";
                    if(tries >= 4) cout << "\\"; cout << endl;
    cout << "\t\t    |"; if(tries >= 5) cout << "  /";
                    if(tries >= 6) cout << " \\"; cout << endl;
    cout << "\t\t    |" << endl;
    cout << "\t\t   _|_" << endl;
	cout << "\t\t    " << endl;
	cout << "\t\t     " << endl;

	SetConsoleTextAttribute(Text_Color,145);
 	for(int i = 0; i < 50;i++){
		cout << "-";
 	}
	SetConsoleTextAttribute(Text_Color,15);
	cout << endl << endl;
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

int HangManPlay(int lv){

	srand (time(nullptr));

	HANDLE Text_Color = GetStdHandle(STD_OUTPUT_HANDLE); // Set for text-color //
		SetConsoleTextAttribute(Text_Color,15);
	vector<string> wordList;
	string word;
	string guessed;
	int number = 3;
	char hint = ' ';

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

		cout << "\t\tLevel : " << lv << endl << endl;
		cout << "Guess The Word : " ;
		 
		for(int i = 0; i < wordLength; i++)
			cout << " " << dispWord[i] << " "; 
		cout << endl << endl;
		 	
			SetConsoleTextAttribute(Text_Color,4);
		cout << "\tWrong Attempts : " << tries << " / " << WRONGTRIES << endl;
			SetConsoleTextAttribute(Text_Color,15);
		cout << "\tGuessed Letters : " << guessed << endl; 

		HangManCreate(tries);
			SetConsoleTextAttribute(Text_Color,15);
		
		if( found == wordLength ){
			SetConsoleTextAttribute(Text_Color,2);
			cout << endl;
			cout << "\t   ******************" << endl;
			cout << "\t   *     You Win    *" << endl;
			cout << "\t   * Bro So Good XD *" << endl;
			cout << "\t   ******************" << endl;

			SetConsoleTextAttribute(Text_Color,15);
			cout << "\t    Answer : " << word << endl;
			Sleep(1500);

			return 1;
			break;
		}
		
		if(tries == 6) break; 

		if(lv > 3){
			cout << "It's too hard for you. We shall give you a hint." << endl;
			cout << "Press 1 to optain hint." << endl << endl;


			if(wordLength < 6) cout << "You have " << number - 2 << " hint." << endl << endl;
			if(wordLength >= 6 && wordLength < 8) cout << "You have " << number - 1 << " hint." << endl << endl;
			if(wordLength >= 8) cout << "You have " << number << " hint." << endl << endl;

		}

		cout<<"Pick a Letter : ";

		guess = getche();
		guess = tolower(guess);

		flagFound = 0;

			if(wordLength < 6){
				if(guess == 49 && number != 0){
					int randnum = rand()%wordLength;
					while(word[randnum] == dispWord[randnum]){
						randnum = rand()%wordLength;
					}

					for(int i=0; i<wordLength; i++){
						if( word[i]==word[randnum] && dispWord[i]=='_' ){
							dispWord[i] = word[randnum];
							found++;
							flagFound = 1; 
						}
					}		

					number--;
				}
			}

			if(wordLength >= 6 && wordLength < 8){
				if(guess == 49 && number != 0){
					int randnum = rand()%wordLength;
					while(word[randnum] == dispWord[randnum]){
						randnum = rand()%wordLength;
					}

					for(int i=0; i<wordLength; i++){
						if( word[i]==word[randnum] && dispWord[i]=='_' ){
							dispWord[i] = word[randnum];
							found++;
							flagFound = 1; 
						}
					}

					number--;
				}
			}

			if(wordLength >= 8){
				if(guess == 49 && number != 0){
					int randnum = rand()%wordLength;
					while(word[randnum] == dispWord[randnum]){
						randnum = rand()%wordLength;
					}

					for(int i=0; i<wordLength; i++){
						if( word[i]==word[randnum] && dispWord[i]=='_' ){
							dispWord[i] = word[randnum];
							found++;
							flagFound = 1; 
						}
					}

					number--;
				}
			}

			if(guess == 27){
				system("cls");
				cout << endl << endl <<"\tEXIT" ;
				Sleep(1500);
				system("cls");
				Exit = true;
				return 0;
				break;
			}
		
		guessed = guessed + " " + guess;
		guessed = Lowercase(guessed);

		if( dispWord.find(guess) != string::npos ) tries++;
		
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
			cout << "\t   ******************" << endl;
			cout << "\t   *    You Lose    *" << endl;
			cout << "\t   * GGEZ Noob Shit *" << endl;
			cout << "\t   ******************" << endl;

			SetConsoleTextAttribute(Text_Color,15);
			cout << "\t  Answer : " << word << endl;
			Sleep(1500);

			return 0;
		}

		return 0;
	}
}




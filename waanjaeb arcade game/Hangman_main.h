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

	if(lv == 7){
		ifstream word;
    	word.open("word/Ultimate Hard Fuck.txt");
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

void Intro(int lv){
	if(lv == 7){

		HANDLE Text_Color = GetStdHandle(STD_OUTPUT_HANDLE);

		cout << endl << endl <<"\tYou Dare Challenge Me?"<< endl << endl;
		Sleep(3000);
		cout << "\t......"<< endl << endl;
		Sleep(3000);
		SetConsoleTextAttribute(Text_Color,4);
		cout << "\tTHEN SUFFER!!!" << endl;
		SetConsoleTextAttribute(Text_Color,15);
		Sleep(3000);
	}
}

int HangManPlay(int lv){

	srand (time(nullptr));

	HANDLE Text_Color = GetStdHandle(STD_OUTPUT_HANDLE); // Set for text-color //
		SetConsoleTextAttribute(Text_Color,15);
	vector<string> wordList;
	string word;
	string guessed;
	int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	char hint = ' ';
	string Rank[7] = {"(Kindergarten Level)","(Elementary School Level)","(High School Level)","(TOIEC Level)","(ILETS Level)","(All ABove Level)","(WTF IS THIS Level)"};

	importWord(lv,wordList);
	if(lv <= 5) word = wordList[rand()%499];
	else if(lv == 6) word = wordList[rand()%2217];
	else if(lv == 7) word = wordList[rand()%289];

	word = Lowercase(word);

	int wordLength = word.length();
	string dispWord (wordLength, '_');
	
	int found = 0;
	int rank = lv-1;
	char guess = ' ';
	int tries = 0;
	int flagFound = 0;
    int WRONGTRIES = 6;
	bool Exit = false;

	Intro(lv);

	while(tries>=0){

		system("cls");

		cout << "\t\tLevel : " << lv << " " << Rank[rank] << endl << endl;
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
			if(lv == 7){
				
				SetConsoleTextAttribute(Text_Color,2);
				cout << endl;
				cout << "\t   ************************" << endl;
				cout << "\t   *       You Win!!!     *" << endl;
				cout << "\t   *  WTF You Not Human!? *" << endl;
				cout << "\t   ************************" << endl;

				SetConsoleTextAttribute(Text_Color,15);
				cout << "\t    Answer : " << word << endl;
				Sleep(1500);

			}else{

				SetConsoleTextAttribute(Text_Color,2);
				cout << endl;
				cout << "\t   ******************" << endl;
				cout << "\t   *     You Win    *" << endl;
				cout << "\t   * Bro So Good XD *" << endl;
				cout << "\t   ******************" << endl;

				SetConsoleTextAttribute(Text_Color,15);
				cout << "\t    Answer : " << word << endl;
				Sleep(1500);

			}

			return 1;
			break;
		}
		
		if(tries == 6) break; 

		if(lv > 3){
			cout << "It's too hard for you. We shall give you a hint." << endl;
			cout << "Press 1 to optain hint." << endl << endl;


			if(wordLength < 6) cout << "You have " << number1 << " hint." << endl << endl;
			if(wordLength >= 6 && wordLength < 8) cout << "You have " << number2 << " hint." << endl << endl;
			if(wordLength >= 8) cout << "You have " << number3 << " hint." << endl << endl;

		}

		cout<<"Pick a Letter : ";

		guess = getche();
		guess = tolower(guess);

		flagFound = 0;

		if(lv > 3){
			if(wordLength < 6  && number1 != 0){
				if(guess == 49){
					number1--;
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
				}
			}

			if(wordLength >= 6 && wordLength < 8 && number2 != 0){
				if(guess == 49){
					number2--;
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
				}
			}

			if(wordLength >= 8 && number3 != 0){
				if(guess == 49){
					number3--;
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
				}
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
			if(lv == 7){

				SetConsoleTextAttribute(Text_Color,4);
				cout << endl;
				cout << "\t   ***************************" << endl;
				cout << "\t   *         You Lose        *" << endl;
				cout << "\t   * Though You Were Smarter.*" << endl;
				cout << "\t   ***************************" << endl;

				SetConsoleTextAttribute(Text_Color,15);
				cout << "\t  Answer : " << word << endl;
				Sleep(1500);

			}else{
				SetConsoleTextAttribute(Text_Color,4);
				cout << endl;
				cout << "\t   ******************" << endl;
				cout << "\t   *    You Lose    *" << endl;
				cout << "\t   * GGEZ Noob Shit *" << endl;
				cout << "\t   ******************" << endl;

				SetConsoleTextAttribute(Text_Color,15);
				cout << "\t  Answer : " << word << endl;
				Sleep(1500);
			}

			return 0;
		}

	}
		return 0;
}




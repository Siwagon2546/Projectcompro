#include <iostream>
#include <windows.h>   // WinApi header

using namespace std;    // std::cout, std::cin

int main()
{
  HANDLE  hConsole;
	/*int k=4;
	cout << "hi" << endl;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "hi" << endl;
  */
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  for(int k;k<256; k++){
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " I want to be nice today!" << endl;
    SetConsoleTextAttribute(hConsole, 16);
  }
  SetConsoleTextAttribute(hConsole, 15);
    cout << " " << endl;
  return 0;
}
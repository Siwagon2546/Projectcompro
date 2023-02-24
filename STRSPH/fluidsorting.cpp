#include "fluidsortingHeader.h"

int main(){
    fluidsort x;
    x.levelparameter(2);
    cout << x.Nbottle << "\t" << x.Nemtybottle << "\t" << x.Nfluidtype << endl << endl ;
    x.createbottle();
    x.createstage();
    //test();
}
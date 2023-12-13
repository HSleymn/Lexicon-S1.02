
// program named mainreturn.cpp
#include <iostream>
#include "carte.h"
using namespace std;




//    defining main with arguments
int main(int argc, char** argv)
{


        cout <<"Il y a " << argv[1] << " joueurs." << endl;
        jeuDeCarte caca;
        initialiserJeuDeCarte(caca);

    return 0;
}

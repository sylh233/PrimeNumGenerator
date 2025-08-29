#include <iostream>
#include <fstream>
#include "pgen.h"

int main()
{
    using namespace std;
    
    ifstream fin;
    int base = 0;
    cin >> base;
    txt_to_p(base);
    return 0;
}
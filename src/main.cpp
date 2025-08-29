#include <iostream>
#include <fstream>
#include "pgen.h"

int main()
{
    using namespace std;

    for (int i =2;i<=10000;i++)
    {
        test(i);
    }
    //write_p(arr_base,top,"p.txt");
    return 0;
}
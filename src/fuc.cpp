#include <fstream>
#include "pgen.h"

void write_p(int arr[],const int top,const char file[])
{
    using namespace std;
    ofstream fout;
    fout.open(file);

    int el = 10;
    int el_c = 1;
    for(int * i = arr;i < arr+top ;i++)
    {
        fout << *i << " ";
        if(el_c < el)
        {
            el_c ++;
        } else
        {
            fout << endl;
            el_c = 1;
        }
    }
}
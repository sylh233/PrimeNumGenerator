#include <fstream>
#include "pgen.h"

void txt_to_p(const int base)
{
    using namespace std;
    ofstream fout;
    int top = 100;
    int arr[top];
    for(int i = base,j=i;i < j+top;i++)
    {
        arr[i-j] = i;
        
    }
    int el = 10;
    int el_c = 1;
    fout.open("p.txt");
    for(int * i = arr;i < arr+top;i++)
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
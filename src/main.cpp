#include <iostream>
#include <fstream>
#include <cmath>
#include "pgen.h"

int main()
{
    using namespace std;

    const int top = 1000;
    int arr_base[top] ;
    for(int i = 0,j=i;i < j+top;i++)
    {
        arr_base[i-j]=i;
    }

    int last = arr_base[top-1];
    for(int i = 2;i < sqrt(top);i++)
    {
        int num = arr_base[i];
        for(int n = num,c = 2;(n*c <= last)&&(n*c!=0);c++)
            arr_base[n*c] = 0;

    }
    write_p(arr_base,top,"p.txt");
    return 0;
}
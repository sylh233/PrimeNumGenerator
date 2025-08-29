#include <iostream>
#include <fstream>
#include "pgen.h"

int main()
{
    using namespace std;

    const int top = 100;
    int arr_base[top];
    for(int i = 0,j=i;i < j+top;i++)
    {
        arr_base[i-j]=i;
    }
    for(int i = 2;i < top;i++)
    {
        int num = arr_base[i];
        int last = arr_base[top-1];
        for(int n = num,c = 2;n*c < last;c++)
        {
            arr_base[n*c] = '/0';
            //cout << n << ":" << n*c <<endl;
        }
    }
    for(int i = 0,j=i;i < j+top;i++)
    {
        if(arr_base[i]!='/0')
            cout << arr_base[i] << " ";
    }
    write_p(arr_base,top,"p.txt");
    return 0;
}
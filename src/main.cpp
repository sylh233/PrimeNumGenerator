#include <iostream>
#include <fstream>
#include <cmath>
#include "pgen.h"

int main()
{
    using namespace std;
    ofstream fout;
    int max = 10000;
    cout << "Input the sup: ";
    cin >> max;

    const int block = 1000;
    int top=block;

    //初始化
    int * ai_ptr = new int [block];

    gen_arr(ai_ptr,top,block);
    gen_p(ai_ptr,top,block,"init.txt");
    fout.open("p.txt");
    fout << "Prime Number Table: " << endl;
    fout.close();
    write_p(ai_ptr,block,"p.txt");

    delete[] ai_ptr;

    top += block;

    while(top<=max)
    {
        int arr_base[block];

        gen_arr(arr_base,top,block);

        cout << "Now Position: " << top <<endl;

        gen_p(arr_base,top,block,"p.txt");
        write_p(arr_base,block,"p.txt");

        top += block;
    }
    cout << "Complete! Any input to exit.";
    cin.get();cin.get();
    return 0;
}
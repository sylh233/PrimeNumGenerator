#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include "pgen.h"

int main()
{
    using namespace std;
    ofstream fout;
    int block = 1000;
    cout << "Shift Modes(More fast more memory): " << endl
    << "fast(1) " << "middle(2) " << "slow(3) "<<endl;
    int mode;
    while(!(cin >> mode))
        {
            cout << "Null! Retry: ";
            cin.clear();
            while(cin.get()!='\n')
                continue;
        }
    cout << "Switch ";
    switch (mode)
    {
    case 1:
        block = 50000;
        cout << "fast";
        break;
    case 2:
        block = 10000;
        cout << "middle";
        break;
    case 3:
    default:
        block = 1000;
        cout << "slow";
        break;
    }
    cout << " Mode." << endl;
    bool cont = true;
    int max = 50000;
    while(cont)
    {   
        cout << "Input the upper: ";
        while(!(cin >> max))
        {
            cout << "Error input! Retry: ";
            cin.clear();
            while(cin.get()!='\n')
                continue;
        }
        
        clock_t beg = clock();
        double sec;
        int top=block;

        //初始化
        int * ai_ptr = new int [block];

        gen_arr(ai_ptr,top,block);
        int arrf[]={2,3,5,7,11,13,17,19,23,29,31,37};
        cout << "Now Position: "<<block<<endl;
        gen_p(ai_ptr,top,block,arrf);
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
        clock_t endt = clock();
        sec = double(endt-beg)/CLOCKS_PER_SEC;
        cout << "Complete! Used "
        << sec << " s." <<endl
        << "Input 'c' to continue. ";
        
        cin.get();
        if(cin.get()!='c')
            cont = false;
        cout << endl;
    }
    return 0;
}
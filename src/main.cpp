#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include "pgen.h"

int main()
{
    using namespace std;
    ofstream fout;
    int max = 10000;
    bool cont = true;
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
        const int block = 1000;
        int top=block;

        //初始化
        int * ai_ptr = new int [block];

        gen_arr(ai_ptr,top,block);
        int arrf[]={2,3,5,7,11,13,17,19,23,29,31,37};
        cout << "Now Position: "<<1000<<endl;
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
        << "Input 'e' to exit. ";
        
        cin.get();
        if(cin.get()=='e')
            cont = false;
        cout << endl;
    }
    return 0;
}
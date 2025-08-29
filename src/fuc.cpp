#include <iostream>
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
        if(*i != 0)
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

    fout.close();
}

void test(int top)
{
    using namespace std;
    //const int top = 100;
    int arr_base[top];
    for(int i = 2,j=0;i < j+top;i++)
    {
        arr_base[i-j]=i;
    }
    //试验使用一个变量记录最大的组成合数的质数
    int try_;
    int last = arr_base[top-1];
    for(int i = 2;i < top;i++)
    {
        int num = arr_base[i];
        for(int n = num,c = 2;n*c <= last&&n!=0;c++)
        {
            if(arr_base[n*c] != 0)
            {
                arr_base[n*c] = 0;
                try_ = n;
                //cout << n << ":" << n*c <<endl;
            }
        }
    }
    /*for(int i = 0,j=i;i < j+top;i++)
    {
        if(arr_base[i]!=0)
            cout << arr_base[i] << " ";
    }*/
    test_p(try_,top,"test.txt");
}

void test_p(int a,int b,const char txtname[])
{
    using namespace std;
    ofstream fout;
    fout.open(txtname);
    fout.close();
    fout.open(txtname,ios::app);
    fout<<a<<" "<<b<<endl;
    fout.close();
}
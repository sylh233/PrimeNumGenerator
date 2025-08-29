#include <iostream>
#include <fstream>
#include <cmath>
#include "pgen.h"

void write_p(int arr[],const int block,const char file[])
{//用于写入文件
    using namespace std;
    ofstream fout;
    fout.open(file,ios::app);

    static int el = 10;
    static int el_c = 1;
    for(int * i = arr;i < arr+block;i++)
    {
        if(*i > 1)//每十个换行
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

void gen_p(int arr[],const int top,int block,const char file[])
{//在数组里踢出合数
    using namespace std;
    int input;
    ifstream fin;
    fin.open(file);
    fin.seekg(22,ios::beg);//从开头的题目后开始读取
    
    while(fin >> input)
    {
        if (input > sqrt(top))
            break;
        int nb = (top-block)/input;
        for(int n = (nb>2?nb:2);input*n <= top;n++)
        {
            for(int i = 0;i <= 1000;i++)
            {
                if(arr[i]==input*n)
                    arr[i]=0;
            }
        }
        
    }
    fin.clear();
    fin.close();
}

void gen_arr(int arr[],int top,int block)
{
    for(int i = top-block,j=i;i <= j+block;i++)//生成数组
    {
        arr[i-j]=i;
    }
}
//测试用
void test(int top)
{
    
}

void test_p(int a,int b,const char txtname[])
{
    using namespace std;
    ofstream fout;
    fout.open(txtname,ios::app);
    fout<<a<<" "<<b<<endl;
    fout.close();
}
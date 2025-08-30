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
    {   int nb = 2;
        if (input > sqrt(top))
            break;
        if(input)
        {
            nb = (top-block)/input;//增加乘数大小，逼近更快
            nb--;
        }
        for(int n = (nb>2?nb:2);input*n <= top;n++)
        {
            int posi = input*n-(top-block);//使用计算当前数字在数组里的位置，直接对元素处理而不是迭代查找，增加速度(超快)
            if(posi >= 0)
                arr[posi]=0;
        }
        
    }
    fin.clear();
    fin.close();
}

void gen_p(int arr[],const int top,int block,int arrf[])
{//在数组里踢出合数//重载版，用于初始化
    using namespace std;
    int input;
    for(int i = 0;i <= 11;i++)
    {
        input=arrf[i];
        cout << input << endl;
        int nb = 2;
        if (input >= sqrt(top))
            break;
        if(input)
        {
            nb = (top-block)/input;//增加乘数大小，逼近更快
        }
        for(int n = (nb>2?nb:2);input*n <= top;n++)
        {
            int posi = input*n-(top-block);//使用计算当前数字在数组里的位置，直接对元素处理而不是迭代查找，增加速度(超快)
            if(posi >= 0)
                arr[posi]=0;
        }
        
    }

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
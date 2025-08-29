#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    
    ifstream fin;
    ofstream fout;
    int top = 10;
    fout.open("p.txt",ios::app);
    for(int i =0;i<=top;i++)
    {
        fout<<i<<" ";
    }
    fout.close();
    fin.open("p.txt");
    int a;
    while(fin >> a)
    {
        cout << a <<" ";
    }
    fin.close();
    return 0;
}
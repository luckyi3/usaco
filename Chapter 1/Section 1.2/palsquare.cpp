/*
ID: luckyi31
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
//#define fin cin
//#define fout cout
using namespace std;
int changebase(char A[], int num, int b)
{
    int i = 0;
    while(num > 0)
    {
        if(num%b > 9)
            A[i++] = num%b - 10 + 'A';
        else
            A[i++] = num%b + '0';
        num /= b;
    }
    return i;
}
int ispal(char A[], int len)
{
    for(int i = 0, j = len-1; i < j; i++, j--)
        if(A[i] != A[j])
            return 0;
    return 1;
}
const int N = 20;
char basenum[N], sqbase[N];
int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int b;
    fin>>b;
    for(int i = 1; i <= 300; i++)
    {
        int len = changebase(sqbase, i*i, b);
        if(ispal(sqbase, len))
        {
            int l = changebase(basenum, i, b);
            int j = 0;
            for(j = l-1; j >= 0; j--)
                fout<<basenum[j];
            fout<<" ";
            for(j = 0; j < len; j++)
                fout<<sqbase[j];
            fout<<endl;
        }
    }
    return 0;
}

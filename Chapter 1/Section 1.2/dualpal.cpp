/*
ID: luckyi31
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
//#define fin cin
//#define fout cout

using namespace std;
const int N = 50;
int A[N];
int base(int A[], int num, int b)
{
    int i = 0;
    while(num > 0)
    {
        A[i++] = num%b + '0';
        num /= b;
    }
    return i;
}
int pal(int A[], int len)
{
    for(int i = 0, j = len-1; i < j; i++, j--)
        if(A[i] != A[j])
            return 0;
    return 1;
}
int ispal(int s)
{
    int cnt = 0;
    for(int i = 2; i <= 10; i++)
    {
        int len = base(A, s, i);
        if(pal(A, len))
            cnt++;
        if(cnt >= 2)
            return 1;
    }
    return 0;
}

int main()
{
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n, s;
    fin>>n>>s;
    for(int i = 0; i < n; i++)
    {
        while(++s)
        {
            if(ispal(s))
            {
                fout<<s<<endl;
                break;
            }
        }
    }
    return 0;
}

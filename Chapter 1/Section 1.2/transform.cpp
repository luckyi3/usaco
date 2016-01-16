/*
ID: luckyi31
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
//#define fin cin
//#define fout cout
using namespace std;
const int N = 15;

int trans1(char a[][N], char b[][N], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != b[j][n-i-1])
                return 0;
    return 1;
}
int trans2(char a[][N], char b[][N], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != b[n-i-1][n-j-1])
                return 0;
    return 1;
}
int trans3(char a[][N], char b[][N], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != b[n-j-1][i])
                return 0;
    return 1;
}
int trans4(char a[][N], char b[][N], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != b[i][n-j-1])
                return 0;
    return 1;
}
int trans5(char a[][N], char b[][N], int n)
{
    char tmp[N][N] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = a[i][n-j-1];
    if(trans1(tmp, b, n) || trans2(tmp, b, n) || trans3(tmp, b, n))
        return 1;
    return 0;
}
int trans6(char a[][N], char b[][N], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != b[i][j])
                return 0;
    return 1;
}
char before[N][N], after[N][N];
int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    int n, i;
    fin>>n;
    for(i = 0; i < n; i++)
        fin>>before[i];
    for(i = 0; i < n; i++)
        fin>>after[i];
    if(trans1(before, after, n))
    {
        fout<<"1"<<endl;
        return 0;
    }
    if(trans2(before, after, n))
    {
        fout<<"2"<<endl;
        return 0;
    }
    if(trans3(before, after, n))
    {
        fout<<"3"<<endl;
        return 0;
    }
    if(trans4(before, after, n))
    {
        fout<<"4"<<endl;
        return 0;
    }
    if(trans5(before, after, n))
    {
        fout<<"5"<<endl;
        return 0;
    }
    if(trans6(before, after, n))
    {
        fout<<"6"<<endl;
        return 0;
    }
    fout<<"7"<<endl;
    return 0;
}

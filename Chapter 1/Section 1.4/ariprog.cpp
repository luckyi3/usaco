/*
ID: luckyi31
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct seq{
    int a, b;
}sequences[10010];

bool h[125010] = {false};

bool cmp(seq x, seq y)
{
    if(x.b != y.b)
        return x.b < y.b;
    else
        return x.a < y.a;
}

int main()
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int n, m;
    fin>>n>>m;
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= m; j++)
            h[i*i + j*j] = true;
    int cnt = 0,large = 2*m*m;
    for(int i = 0; i < large; i++)
        for(int j = 1; i + j*(n-1) <= large; j++)
        {
            int k = 0;
            for(k = 0; k < n; k++)
                if(!h[i+k*j])
                    break;
            if(k == n)
            {
                sequences[cnt].a = i;
                sequences[cnt].b = j;
                cnt++;
            }
        }
    if(cnt == 0)
        fout<<"NONE"<<endl;
    else
    {
        sort(sequences, sequences+cnt, cmp);
        for(int i = 0; i < cnt; i++)
            fout<<sequences[i].a<<" "<<sequences[i].b<<endl;
    }
    return 0;
}

/*
ID: luckyi31
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
//#define fin cin
//#define fout cout

using namespace std;
int num[50], a[50];
int isin(int a, int n)
{
    int i = 0, flag = 0;
    for(i = 0; i < n; i++)
        if(a == num[i])
            flag = 1;
    return flag;
}

int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int n, i, j, k, l, m, cnt = 0;
    fin>>n;
    for(i = 0; i < n; i++)
        fin>>num[i];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
                for(l = 0; l < n; l++)
                    for(m = 0; m < n; m++)
                    {
                        a[0] = num[m] * num[k];
                        a[1] = num[m] * num[j];
                        a[2] = num[m] * num[i];
                        a[3] = num[l] * num[k];
                        a[4] = num[l] * num[j];
                        a[5] = num[l] * num[i];
                        a[1] += a[0]/10;
                        a[0] %= 10;
                        a[2] += a[1]/10;
                        a[1] %= 10;
                        //if(a[2] >= 10)
                          //  break;
                        a[4] += a[3]/10;
                        a[3] %= 10;
                        a[5] += a[4]/10;
                        a[4] %= 10;
                        //if(a[5] >= 10)
                          //  break;
                        a[6] = a[1] + a[3];
                        a[7] = a[2] + a[4] + a[6]/10;
                        a[6] %= 10;
                        a[8] =  a[5] + a[7]/10;
                        a[7] %= 10;
                        //if(a[8] >= 10)
                          //  break;
                        int p = 0;
                        for(p = 0; p < 9; p++)
                            if(!isin(a[p],n))
                                break;
                        if(p == 9)
                            cnt++;
                    }
        fout<<cnt<<endl;
    return 0;
}

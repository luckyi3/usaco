/*
ID: luckyi31
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    char group[20][20];
    int money[20];
    for(int i = 0; i < 20; i++)
        money[i] = 0;
    int np;
    fin>>np;
    for(int i = 0; i < np; i++)
        fin>>group[i];
    for(int i = 0; i < np; i++)
    {
        char give[20], receive[20];
        fin>>give;
        int init, num, avg, left;
        fin>>init>>num;
        int j;
        for(j = 0; j < np && strcmp(give, group[j]) != 0; j++)
            ;
        if(num != 0)
        {
            left = init % num;
            avg = init / num;
            money[j] += (left - init);
        }
        for(int k = 0; k < num; k++)
        {
            fin>>receive;
            for(j = 0; j < np && strcmp(receive, group[j]) != 0; j++)
                ;
            money[j] += avg;
        }
    }
    for(int i = 0; i < np; i++)
        fout<<group[i]<<" "<<money[i]<<endl;

    return 0;
}

/*
 ID: luckyi31
 PROG: skidesign
 LANG: C++
 */

#include <iostream>
#include <limits.h>
#include <fstream>
#include <algorithm>
using namespace std;

//#define fin cin
//#define fout cout

int hills[1000+100];

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int N;
    fin>>N;
    int max = 0;
    for(int i = 0; i < N; i++)
    {
        fin>>hills[i];
        if(hills[i] > max)
            max = hills[i];
    }
    int res = INT_MAX;
    for(int i = 17; i <= max; i++)
    {
        int tmp = 0;
        for(int j = 0; j < N; j++)      //将高度的范围设置在[i-17,i]之间，每个范围有一个cost，res保存最小者
        {
            if(hills[j] < i - 17)
                tmp += (i-hills[j] -17)*(i-hills[j] -17);
            if(hills[j] > i)
                tmp += (hills[j] - i)*(hills[j] - i);
        }
        if(tmp < res)
            res = tmp;
    }
    fout<<res<<endl;
    return 0;
}

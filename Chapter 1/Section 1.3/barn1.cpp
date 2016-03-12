/*
ID: luckyi31
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct stall{
    int num;
    int next;
};
bool cmp1(stall a, stall b)
{
    return a.num < b.num;
}
bool cmp2(stall a, stall b)
{
    return a.next > b.next;
}
const int N = 200+10;
stall cow[N];
int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int m, s, c, i;
    fin>>m>>s>>c;
    if(m >= c)
    {
        fout<<c<<endl;
        return 0;
    }
    for(i = 0; i < c; i++)
        fin>>cow[i].num;
    sort(cow, cow+c, cmp1);
    int totallen = cow[c-1].num - cow[0].num + 1;      //先使用一块覆盖所有的
    for(i = 0; i < c-1; i++)
        cow[i].next = cow[i+1].num - cow[i].num - 1;
    cow[i].next = 0;
    sort(cow, cow+c, cmp2);        //将间距最大的去掉，每去掉一个间距使用木板的数量多1
    for(i = 0; i < m-1; i++)
        totallen -= cow[i].next;
    fout<<totallen<<endl;
    return 0;
}

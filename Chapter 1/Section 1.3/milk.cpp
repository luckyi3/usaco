/*
ID: luckyi31
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
//#define fin cin
//#define fout cout
using namespace std;
struct milk{
    int price;
    int amount;
};
bool cmp(milk a, milk b)
{
    return a.price < b.price;
}
const int N = 5000 + 10;
milk farmer[N];
int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n,m,i,cost = 0;
    fin>>n>>m;
    for(i = 0; i < m; i++)
        fin>>farmer[i].price>>farmer[i].amount;
    sort(farmer, farmer+m, cmp);
    for(i = 0; i < m; i++)
    {
        if(n == 0)
            break;
        if(n > farmer[i].amount)
        {
            cost += farmer[i].price*farmer[i].amount;
            n -= farmer[i].amount;
        }
        else
        {
            cost += farmer[i].price*n;
            n = 0;
        }
    }
    fout<<cost<<endl;
    return 0;
}

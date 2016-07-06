/*
ID: luckyi31
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Fraction{
    int m, n;
};
int gcd(int m, int n)
{
    if(n == 0)
        return m;
    return gcd(n, m%n);
}
bool cmp(Fraction x, Fraction y)
{
    return x.m*y.n < y.m*x.n;
}
int main()
{
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
    int n;
    cin>>n;
    vector<Fraction> frac;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(gcd(i, j) == 1){
                Fraction tmp;
                tmp.m = i, tmp.n = j;
                frac.push_back(tmp);
            }
        }
    }
    sort(frac.begin(), frac.end(), cmp);
    cout<<"0/1"<<endl;
    //for(int i = 0; i < frac.size(); i++)
    //    cout<<frac[i].m<<"/"<<frac[i].n<<endl;
    for(vector<Fraction>::iterator it = frac.begin(); it != frac.end(); it++)
        cout<<it->m<<"/"<<it->n<<endl;
    cout<<"1/1"<<endl;
    return 0;
}

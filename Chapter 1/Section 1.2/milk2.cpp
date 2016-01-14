/*
 ID: luckyi31
 PROG: milk2
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
//#define fin cin
//#define fout cout
using namespace std;
struct farmer{
    int start;
    int end;
};
const int N = 5000;
farmer farmers[N];
bool cmp(farmer a, farmer b)
{
    return a.start < b.start;
}

int main(int argc, const char * argv[]) {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n, time1=0, time2=0;
    fin>>n;
    for(int i = 0; i < n; i++)
    {
        fin>>farmers[i].start>>farmers[i].end;
    }
    sort(farmers, farmers+n, cmp);
    int s = 0, t = 0;
    for(int i = 0; i < n; i++)
    {
        if(farmers[t].end <= farmers[i].end && farmers[t].end >= farmers[i].start)
            t = i;
        if(farmers[t].end-farmers[s].start > time1)
            time1 = farmers[t].end - farmers[s].start;
        if(farmers[t].end < farmers[i].start)
        {
            if(farmers[i].start - farmers[t].end > time2)
                time2 = farmers[i].start - farmers[t].end;
            //cout<<i<<" "<<t<<" "<<time2<<endl;
            s = t = i;
        }
    }
    fout<<time1<<" "<<time2<<endl;
    return 0;
}

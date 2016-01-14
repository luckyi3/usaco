/*
ID: luckyi3
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
//#define fin cin
//#define fout cout

using namespace std;

char necklace[500];

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;
    fin>>n>>necklace;
    int maximum = 0;
    for(int i = 0; i < n && necklace[i] != 0; i++)
    {
        if(necklace[i] == 'b' && necklace[(i+1)%n] == 'r')
        {
            int cnt = 1, j = (i-1+n)%n, k = (i+1+n)%n;
            while(j != k && necklace[j] != 'r')
            {
                cnt++;
                j = (j-1+n)%n;
            }
            while(k != j && necklace[k] != 'b')
            {
                cnt++;
                k = (k+1+n)%n;
            }
            if(cnt > maximum)
                maximum = cnt;
        }
        if(necklace[i] == 'r' && necklace[(i+1)%n] == 'b')
        {
            int cnt = 1, j = (i-1+n)%n, k = (i+1+n)%n;
            while(j != k && necklace[j] != 'b')
            {
                cnt++;
                j = (j-1+n)%n;
            }
            while(k != j && necklace[k] != 'r')
            {
                cnt++;
                k = (k+1+n)%n;
            }
            if(cnt > maximum)
                maximum = cnt;
        }
    }
    if(maximum == 0)
        fout<<n<<endl;
    else
        fout<<maximum<<endl;
    return 0;
}

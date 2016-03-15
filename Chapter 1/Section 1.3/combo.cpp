/*
 ID: luckyi31
 PROG: combo
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;
int cnt[110];

int main(int argc, const char * argv[]) {
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    
    int n, john[10], master[10];
    fin>>n;
    int i, j;
    for(i = 0; i < 3; i++)
    {
        fin>>john[i];
        //john[i]--;
    }
    for(i = 0; i < 3; i++)
    {
        fin>>master[i];
        //master[i]--;
    }
    int div = 1;
    for(i = 0; i < 3; i++)
    {
        int p = 0;
        for(j = 0; j < n; j++)
            cnt[j] = 0;
        for(j = (john[i]+n-2)%n; j != (john[i]+n+3)%n; j = (j+n+1)%n)
        {
            cnt[j]++;
        }
        for(j = (master[i]+n-2)%n; j != (master[i]+n+3)%n; j = (j+n+1)%n)
        {
            cnt[j]++;
        }
        for(j = 0; j < n; j++)
            if(cnt[j] == 2)
                p++;
        div *= p;
    }
    if(n >= 5)
        fout<<250-div<<endl;
    else
        fout<<n*n*n<<endl;
    return 0;
}

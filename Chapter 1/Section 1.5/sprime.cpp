/*
 ID:   luckyi31
 PROG: sprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int n;
ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool isprime(int a)
{
    if(a <= 1)
        return false;
    //int len = sqrt(a);
    for(int i = 2; i*i <= a; i++)
        if(a%i == 0)
            return false;
    return true;
}

void ssearch(int pre, int cnt)
{
    if(cnt == n)
        fout<<pre<<endl;
    else{
        int ans = 0;
        for(int i = 1; i <= 9; i+=2){
            ans = pre*10 + i;
            if(isprime(ans))
                ssearch(ans, cnt+1);
        }
    }
}

int main(int argc, const char * argv[]) {
//    ifstream fin("sprime.in");
//    ofstream fout("sprime.out");
    fin>>n;
    ssearch(2, 1);
    ssearch(3, 1);
    ssearch(5, 1);
    ssearch(7, 1);
    return 0;
}

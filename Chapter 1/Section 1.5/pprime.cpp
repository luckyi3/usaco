/*
 ID:   luckyi31
 PROG: pprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

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

/*bool ispal(int a)
{
    int m = a, n = 0;
    while(m != 0){
        n = n*10 + m%10;
        m /= 10;
    }
    return a == n;
}*/

int main(int argc, const char * argv[]) {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a, b;
    fin>>a>>b;
    /*
    for(int i = a; i <= b; i++)
        if(i%2 != 0 && ispal(i) && isprime(i))
            fout<<i<<endl;
     */
    int ans = 0;
    //d = 1
    for(int i = a; i < 10; i++)
        if(isprime(i))
            fout<<i<<endl;
    //d = 2
    if(b > 10)
        for(int d1 = 1; d1 <= 9; d1+=2){
            ans = 10*d1+d1;
            if(ans >= a && ans <= b && isprime(ans))
                fout<<ans<<endl;
        }
    //d = 3
    if(b > 100)
        for(int d1 = 1; d1 <= 9; d1+=2)
            for(int d2 = 0; d2 <= 9; d2++){
                ans = 100*d1 + 10*d2 + d1;
                if(ans >= a && ans <= b && isprime(ans))
                    fout<<ans<<endl;
            }
    //d = 4
    if(b > 1000)
        for(int d1 = 1; d1 <= 9; d1+=2)
            for(int d2 = 0; d2 <= 9; d2++){
                ans = 1000*d1 + 100*d2 + 10*d2 + d1;
                if(ans >= a && ans <= b && isprime(ans))
                    fout<<ans<<endl;
            }
    //d = 5
    if(b > 10000)
        for(int d1 = 1; d1 <= 9; d1+=2)
            for(int d2 = 0; d2 <= 9; d2++)
                for(int d3 = 0; d3 <= 9; d3++){
                    ans = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
                    if(ans >= a && ans <= b && isprime(ans))
                        fout<<ans<<endl;
                }
    //d = 6
    if(b > 100000)
        for(int d1 = 1; d1 <= 9; d1+=2)
            for(int d2 = 0; d2 <= 9; d2++)
                for(int d3 = 0; d3 <= 9; d3++){
                    ans = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
                    if(ans >= a && ans <= b && isprime(ans))
                        fout<<ans<<endl;
                }
    //d = 7
    if(b > 1000000)
        for(int d1 = 1; d1 <= 9; d1+=2)
            for(int d2 = 0; d2 <= 9; d2++)
                for(int d3 = 0; d3 <= 9; d3++)
                    for(int d4 = 0; d4 <= 9; d4++){
                        ans = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
                        if(ans >= a && ans <= b && isprime(ans))
                            fout<<ans<<endl;
                    }
    //d = 8
    if(b > 10000000)
        for(int d1 = 1; d1 <= 9; d1+=2)
            for(int d2 = 0; d2 <= 9; d2++)
                for(int d3 = 0; d3 <= 9; d3++)
                    for(int d4 = 0; d4 <= 9; d4++){
                        ans = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;
                        if(ans >= a && ans <= b && isprime(ans))
                            fout<<ans<<endl;
                    }

    return 0;
}

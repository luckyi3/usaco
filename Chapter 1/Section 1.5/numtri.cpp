/*
 ID:   luckyi31
 PROG: numtri
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int triangle[1010][1010];
int main(int argc, const char * argv[]) {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int r;
    fin>>r;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= i; j++){
            fin>>triangle[i][j];
            if(i > 1){
                int tmp1 = 0, tmp2 = 0;
                //if(j-1 >= 1)
                    tmp1 = triangle[i][j]+triangle[i-1][j-1];
                //if(j < i)
                    tmp2 = triangle[i][j]+triangle[i-1][j];
                triangle[i][j] = tmp1>tmp2?tmp1:tmp2;
            }
        }
    }
    int ans = triangle[r][1];
    for(int i = 2; i <= r; i++)
        if(ans < triangle[r][i])
            ans = triangle[r][i];
    fout<<ans<<endl;
    return 0;
}

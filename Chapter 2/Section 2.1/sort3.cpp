/*
ID: luckyi31
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int const N = 1010;

int seq[N], dup[N];

void swap(int i, int j)
{
    int temp = seq[i];
    seq[i] = seq[j];
    seq[j] = temp;
}

int main()
{
    ifstream cin("sort3.in");
    ofstream cout("sort3.out");
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>seq[i];
        dup[i] = seq[i];
    }
    sort(dup, dup+n+1);
    int cnt = 0, unsort = 0;
    for(int i = 1; i <= n; i++){
        //如果两个数交换位置后在最终位置则只需一次交换，除去这些剩下的不在最终位置的个数一定是3的倍数
        //而且每3个通过两次交换就会到达最终位置
        if(seq[i] != dup[i]){
            unsort++;
            for(int j = i+1; j <= n; j++){
                if(seq[j] == dup[i] && dup[j]  == seq[i]){
                    cnt++;
                    swap(i, j);
                    break;
                }
            }
        }
    }
    cnt += 2*(unsort-cnt)/3;
    cout<<cnt<<endl;
    return 0;
}

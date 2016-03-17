/*
ID: luckyi3
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int a, b, c;
int milk[25];
int mark[400][3];
int pos = 0;
void dfs(int x, int y, int z)
{
    for(int i = 0; i < pos; i++)
        if(x == mark[i][0] && y == mark[i][1] && z == mark[i][2])   //当状态出现过就不再递归
            return;
    //标记当前状态
    mark[pos][0] = x;
    mark[pos][1] = y;
    mark[pos][2] = z;
    pos++;
    if(x == 0)
        milk[z] = 1;
    //互相倒
    if(x > 0 && y < b)
    {
        if(b-y > x)
            dfs(0, x+y, z);
        else
            dfs(x+y-b, b, z);
    }
    if(x > 0 && z < c)
    {
        if(c-z > x)
            dfs(0, y, x+z);
        else
            dfs(x+z-c, y, c);
    }
    if(y > 0 && x < a)
    {
        if(a-x > y)
            dfs(x+y, 0, z);
        else
            dfs(a, x+y-a, z);
    }
    if(y > 0 && z < c)
    {
        if( c-z > y)
            dfs(x, 0, y+z);
        else
            dfs(x, y+z-c, c);
    }
    if(z > 0 && x < a)
    {
        if(a-x > z)
            dfs(x+z, y, 0);
        else
            dfs(a, y, x+z-a);
    }
    if(z > 0 && y < b)
    {
        if(b-y > z)
            dfs(x, y+z, 0);
        else
            dfs(x, b, y+z-b);
    }
}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin>>a>>b>>c;
    int x = 0, y = 0, z = c;
    dfs(x, y, z);
    int flag = 1;
    for(int i = 0; i <= c; i++)
        if(milk[i])
        {
            if(flag)
            {
                fout<<i;
                flag = 0;
            }
            else
                fout<<" "<<i;
        }
    fout<<endl;
    return 0;
}

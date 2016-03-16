/*
ID: luckyi31
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct point{
    int x, y;
    int next;
    int connect;
};

bool cmp(point a, point b)
{
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

point holes[15];
int pairs = 0;
int n;
bool check()
{
    for(int i = 0; i < n; i++)
    {
        int cnt = n, next = holes[i].connect;
        while(cnt--)
        {
            next = holes[next].next;
            if(next == i)
                return true;
            if(next == -1)
                break;
            next = holes[next].connect;
        }
    }
    return false;
}
void dfs()
{
    int i = 0;
    for(; i < n; i++)
        if(holes[i].connect == -1)
            break;
    if(i == n){
        if(check())
            pairs++;
        return;
    }
    for(int j = i+1; j < n; j++)
    {
        if(holes[j].connect == -1)
        {
            holes[i].connect = j;
            holes[j].connect = i;
            dfs();
            holes[i].connect = -1;
            holes[j].connect = -1;
        }
    }
}

int main()
{
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");
    fin>>n;
    for(int i = 0; i < n; i++)
        fin>>holes[i].x>>holes[i].y;
    sort(holes, holes+n, cmp);
    for(int i = 0; i < n-1; i++){
        if(holes[i].y == holes[i+1].y && holes[i].x < holes[i+1].x)
            holes[i].next = i+1;
        else
            holes[i].next = -1;
        holes[i].connect = -1;
    }
    holes[n-1].next = -1;
    holes[n-1].connect = -1;
    dfs();
    fout<<pairs<<endl;
    return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int a[13][2];
int b[13];
int c[13];

bool check()
{
    for(int i = 1; i <= N; i++)
    {
        int tmp = i;
        for(int j = 0; j < N; j++)
            tmp = c[b[tmp]];
        if(tmp != 0)
            return true;
    }
    return false;
}

int dfs()
{
    int i = 0, sum =0 ;
    for(i = 1; i <= N; i++)
        if(b[i] ==  0)
            break;
    if(i > N)
        if(check())
            return 1;
        else
            return 0;
    for(int j = i+1; j <= N; j++)
        if(b[j] == 0)
        {
            b[i] = j;
            b[j] = i;
            sum += dfs();
            b[i] = 0;
            b[j] = 0;
        }
        return sum;
}

int main()
{
    cin>>N;
    for(int i = 1; i <= N; i++)
        cin>>a[i][0]>>a[i][1];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(a[j][0] > a[i][0] && a[i][1] == a[j][1])
                if(c[i] == 0 || a[j][0] - a[i][0] < a[c[i]][0] - a[i][0])
                    c[i] = j;

    cout<<dfs()<<endl;
    return 0;
}
*/

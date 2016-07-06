/*
ID: luckyi31
PROG: castle
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int N = 60;
int graph[N][N], vis[N][N];
int cnt[N*N];

//遍历连通房间的时候用vis存储房间编号
void dfs(int i, int j, int roomNum)
{
    if(vis[i][j] == 0)
        vis[i][j] = roomNum;
    else
        return;
    if((graph[i][j] & 1) == 0)
        dfs(i, j-1, roomNum);
    if((graph[i][j] & 2) == 0)
        dfs(i-1, j, roomNum);
    if((graph[i][j] & 4) == 0)
        dfs(i, j+1, roomNum);
    if((graph[i][j] & 8) == 0)
        dfs(i+1, j, roomNum);
}

int main()
{
    ifstream cin("castle.in");
    ofstream cout("castle.out");
    memset(graph, 0, sizeof(graph));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    int n, m;
    cin>>m>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin>>graph[i][j];
    }
    int rooms = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                rooms++;
                dfs(i, j, rooms);
            }
            cnt[vis[i][j]]++;
        }
    }
    cout<<rooms<<endl;
    for(int i = 1; i <= rooms; i++)
        if(cnt[i] > cnt[0])
            cnt[0] = cnt[i];
    cout<<cnt[0]<<endl;
    int comb = 0, ri = n, rj = 1;
    char direction = 'N';
    for(int j = 1; j <= m; j++){
        for(int i = n; i >= 1; i--){
            if(i != 1){
                if(vis[i][j] != vis[i-1][j] && cnt[vis[i][j]]+cnt[vis[i-1][j]] > comb){
                    ri = i, rj = j, comb = cnt[vis[i][j]]+cnt[vis[i-1][j]], direction = 'N';
                }
            }
            if(j != m){
                if(vis[i][j] != vis[i][j+1] && cnt[vis[i][j]]+cnt[vis[i][j+1]] > comb)
                    ri = i, rj = j, comb = cnt[vis[i][j]]+cnt[vis[i][j+1]], direction = 'E';
            }
        }
    }
    cout<<comb<<endl;
    cout<<ri<<" "<<rj<<" "<<direction<<endl;
    return 0;
}

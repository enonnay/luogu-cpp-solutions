#include <bits/stdc++.h>
using namespace std;
int n,m,t1,sx,sy,fx,fy,t[10][10],vis[10][10],ans;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int x,int y){
    if(x==fx&&y==fy){
        ans++;
        return;
    }
    for(int i=0;i<=3;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m||t[nx][ny]==1||vis[nx][ny]==1) continue;
        vis[nx][ny] = 1;
        dfs(nx,ny);
        vis[nx][ny] = 0;
    }
}

int main(){
    cin >>n>>m>>t1;
    cin >>sx>>sy>>fx>>fy;
    for(int i=1;i<=t1;i++){
        int tx,ty;
        cin >>tx>>ty;
        t[tx][ty] = 1;
    }
    vis[sx][sy] = 1;
    dfs(sx,sy);
    cout << ans;
    return 0;
}
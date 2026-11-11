#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char c;
bool a[105][105],vis[105][105];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
queue<pair<int,int>> q;

void bfs(int sx,int sy){
    q.push(make_pair(sx,sy));
    vis[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0&&a[nx][ny]==1){
                vis[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c;
            if(c=='W') a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1&&vis[i][j]==0){
                ans++;
                bfs(i,j);
            }
        }
    }
    cout << ans;
    return 0;
}
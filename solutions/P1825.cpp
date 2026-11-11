#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char a[305][305];
bool vis[305][305];

struct Node{
    int r,c,step;
};

int main(){
    queue<Node> q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]=='@'){
                int sr = i;
                int sc = j;
                q.push({sr,sc,0});
                vis[sr][sc]=1;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().r;
        int y = q.front().c;
        int s = q.front().step;
        q.pop();
        if(a[x][y]=='='){
            cout<<s;
            return 0;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]=='='){
                cout<<s+1;
                return 0;
            }
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]=='.'&&!vis[nx][ny]){
                q.push({nx,ny,s+1});
                vis[nx][ny] = 1;
            }
            else if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]!='.'&&a[nx][ny]!='#'&&!vis[nx][ny]){
                for(int k=1;k<=n;k++){
                    for(int j=1;j<=m;j++){
                        if(a[k][j]==a[nx][ny]&&(k!=nx||j!=ny)){
                            q.push({k,j,s+1});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int n;
int a[35][35];
bool vis[35][35];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    queue<pair<int,int>> q;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((i == 1 || i == n || j == 1 || j == n) && a[i][j] == 0){
                vis[i][j] = true;
                q.push({i,j});
            }
    
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
        
        if(nx<1||nx>n||ny<1||ny>n) continue;

        if(!vis[nx][ny]&&a[nx][ny]==0){
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0&&!vis[i][j])
                cout<<2<<" ";
            else
                cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
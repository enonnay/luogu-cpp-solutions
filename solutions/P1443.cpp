#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,f[405][405];
bool vis[405][405];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,-2,-1,1,2};
queue<pair<int,int>> q;

int main(){
    memset(f,-1,sizeof(f));
    cin>>n>>m>>x>>y;
    f[x][y]=0;
    vis[x][y]=1;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i=1;i<=8;i++){
            int u = xx + dx[i-1];
            int v = yy + dy[i-1];
            if(u<1||u>n||v<1||v>m||vis[u][v]==1) continue;
            vis[u][v]=1;
            f[u][v] = f[xx][yy]+1;
            q.push(make_pair(u,v));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%-5d",f[i][j]);
        cout<<endl;
    }
    return 0;
}
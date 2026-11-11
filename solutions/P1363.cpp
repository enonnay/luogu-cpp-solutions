#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1505;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int vis[MAXN][MAXN][3];
int n,m;
bool a[MAXN][MAXN],fl;

void dfs(int x,int y,int lx,int ly){
    if(fl) return;
    if(vis[x][y][0]&&(vis[x][y][1]!=lx||vis[x][y][2]!=ly)){
        fl=1;
        return;
    }
    vis[x][y][1]=lx;
    vis[x][y][2]=ly;
    vis[x][y][0]=1;
    for(int i=0;i<4;i++){
        int nx=(x+dx[i]+n)%n;
        int ny=(y+dy[i]+m)%m;
        int nlx=lx+dx[i];
        int nly=ly+dy[i];
        if(!a[nx][ny]){
            if(!vis[nx][ny][0]||vis[nx][ny][1]!=nlx||vis[nx][ny][2]!=nly){
                dfs(nx,ny,nlx,nly);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char ch;
    int stx,sty;
    while(cin>>n>>m){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        fl=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>ch;
                if(ch=='#') a[i][j]=1;
                if(ch=='S'){
                    stx=i;
                    sty=j;
                }
            }
        }
        dfs(stx,sty,stx,sty);
        if(fl){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}
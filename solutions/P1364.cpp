#include <bits/stdc++.h>
using namespace std;
struct Node{
    int root;
    int left;
    int right;
    int people;
}t[105];
bool vis[105];
int dis[105][105];

void dfs(int cur,int d,int start){
    dis[start][cur] = d;
    vis[cur] = true;
    if(t[cur].left&&!vis[t[cur].left]){
        dfs(t[cur].left,d+1,start);
    }
    if(t[cur].right&&!vis[t[cur].right]){
        dfs(t[cur].right,d+1,start);
    }
    if(t[cur].root&&!vis[t[cur].root]){
        dfs(t[cur].root,d+1,start);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].people>>t[i].left>>t[i].right;
        t[t[i].left].root = i;
        t[t[i].right].root = i;
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dfs(i,0,i);
    }
    int ans = 2147483647;
    for(int i=1;i<=n;i++){
        int dist = 0;
        for(int j=1;j<=n;j++){
            dist+=dis[i][j]*t[j].people;
        }
        ans = min(ans,dist);
    }
    cout<<ans;
    return 0;
}
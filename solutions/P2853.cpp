#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;
vector<int> adj[MAXN];
bool vis[MAXN];
int cnt[MAXN],cow[MAXN],ans;

void dfs(int u){
    vis[u]=true;
    cnt[u]++;
    for(int i:adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

int main(){
    int k,n,m,u,v;
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++){
        cin>>cow[i];
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=k;i++){
        memset(vis,0,sizeof(vis));
        dfs(cow[i]);
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

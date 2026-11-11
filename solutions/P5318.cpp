#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> G[MAXN];
bool vis[MAXN];

void dfs(int x){
    vis[x]=1;
    cout<<x<<" ";
    for(int i=0;i<G[x].size();i++){
        int v = G[x][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    int n,m;
    queue<int> q;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        sort(G[i].begin(), G[i].end());
    }
    q.push(1);
    vis[1]=1;
    dfs(1);
    cout<<endl;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0;i<G[p].size();i++){
            if(!vis[G[p][i]]){
                q.push(G[p][i]);
                vis[G[p][i]]=1;
            }
        }
        cout<<p<<" ";
    }
    return 0;
}


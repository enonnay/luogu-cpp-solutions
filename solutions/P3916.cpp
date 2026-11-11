#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> G[MAXN];
int a[MAXN];

void bfs(int x){
    if(a[x]) return;
    queue<int> q;
    q.push(x);
    a[x]=x;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0;i<G[p].size();i++){
            if(a[G[p][i]]) continue;
            q.push(G[p][i]);
            a[G[p][i]]=x;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[v].push_back(u);//反向，记录每个点的入边
    }
    for(int i=n;i>=1;i--){
        bfs(i);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
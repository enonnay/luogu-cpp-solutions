#include <bits/stdc++.h>
using namespace std;
int fa[105],dep[105],wid_cnt[105];

int get_depth(int u){
    if(u==1) return dep[1]=1;
    if(dep[u]!=0) return dep[u];
    return dep[u] = get_depth(fa[u])+1;
}

int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]>dep[v]){
        u = fa[u];
    }
    while(u!=v){
        u = fa[u];
        v = fa[v];
    }
    return u;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        fa[b]=a;
    }
    int max_depth = 0;
    for(int i=1;i<=n;i++){
        int d = get_depth(i);
        max_depth = max(max_depth,d);
        wid_cnt[d]++;
    }
    cout<<max_depth<<endl;
    int max_wid = 0;
    for(int i=1;i<=n;i++){
        max_wid = max(max_wid,wid_cnt[i]);
    }
    cout<<max_wid<<endl;
    int x,y;
    cin>>x>>y;
    int a = lca(x,y);
    int ans = dep[y]-dep[a]+2*(dep[x]-dep[a]);
    cout<<ans<<endl;
    return 0;
}

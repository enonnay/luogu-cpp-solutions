#include <bits/stdc++.h>
using namespace std;
int num[5005],in[5005],out[5005],ans;
vector<int> t[5005];

int dfs(int u){
    if(!out[u]){
        return 1;
    }
    if(num[u]){
        return num[u];
    }
    int path=0;
    for(int v:t[u]){
        path = (path+dfs(v))%80112002;
    }
    return num[u]=path;
}

int main(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        out[a]++;
        in[b]++;
        t[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!in[i]){
            ans = (ans+dfs(i))%80112002;
        }
    }
    cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,vis[20],ans[20];

void dfs(int a){
    if(a>n){
        for(int i=1;i<=n;i++) printf("%5d ",ans[i]);
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        vis[i]=1;
        ans[a]=i;
        dfs(a+1);
        vis[i]=0;
    }
}

int main(){
    cin >> n;
    dfs(1);
    return 0;
}
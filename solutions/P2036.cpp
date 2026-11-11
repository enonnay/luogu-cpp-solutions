#include <bits/stdc++.h>
using namespace std;
int n,a[20],b[20];
int ans = 0x7fffffff;

void dfs(int c,int x,int y){
    if(c>n){
        if(x==1&&y==0) return;
        ans = min(abs(x-y),ans);
        return;
    }
    dfs(c+1,x*a[c],y+b[c]);
    dfs(c+1,x,y);
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    dfs(1,1,0);
    cout<<ans;
    return 0;
}

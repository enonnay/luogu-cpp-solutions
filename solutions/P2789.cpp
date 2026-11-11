#include <bits/stdc++.h>
using namespace std;
bool num[305];

void dfs(int n,int cnt){
    if(n==0){
        num[cnt]=1;
        return;
    }
    for(int i=1;i<=n;i++){
        dfs(n-i,cnt+(n-i)*i);
    }
}

int main(){
    int n;
    int ans=0;
    cin>>n;
    dfs(n,0);
    int total=n*(n-1)/2;
    for(int i=0;i<=total;i++){
        if(num[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;

}
#include <bits/stdc++.h>
using namespace std;
int n,k,a[25],ans;

bool isprime(int p){
    if(p==2) return true;
    if(p%2==0||p==1) return false;
    for(int i=3;i*i<=p;i++){
        if(p%i==0) return false;
    }
    return true;
}

void dfs(int now,int sum,int start){
    if(now==k){
        if(isprime(sum)) ans++;
        return;
    }
    for(int i=start;i<=n-k+now+1;i++){
        dfs(now+1,sum+a[i],i+1);
    }
    return;
}

int main(){
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;

}
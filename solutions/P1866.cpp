#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int m[60];

int main(){
    int n;
    long long ans=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    sort(m,m+n+1);
    for(int i=1;i<=n;i++){
        ans = ans*(m[i]-i+1)%mod;
    }
    cout<<ans;
    return 0;
}
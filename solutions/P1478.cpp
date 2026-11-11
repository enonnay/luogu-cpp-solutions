#include <bits/stdc++.h>
using namespace std;
int n,s,a,b;
vector<int> f;
int dp[5005];

int main(){
    cin>>n>>s>>a>>b;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x<=a+b){
            f.push_back(y);
        }
    }
    for(int i=0;i<f.size();i++){
        for(int j=s;j>=f[i];j--){
           dp[j] = max(dp[j],dp[j-f[i]]+1);
        }
    }
    cout<<dp[s];
    return 0;
}

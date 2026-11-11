#include <bits/stdc++.h>
using namespace std;
int t,m,dp[105][1005];
struct H{
    int time;
    int value;
} h[105];

int main(){
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin >> h[i].time >> h[i].value;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            if(j>=h[i].time){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-h[i].time]+h[i].value);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[m][t];
    return 0;
}

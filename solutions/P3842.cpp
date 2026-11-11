#include <bits/stdc++.h>
using namespace std;
int L[20005],R[20005],dp[20005][2],n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>L[i]>>R[i];
	dp[1][0] = R[1]-1+R[1]-L[1];
	dp[1][1] = R[1]-1;
	for(int i=2;i<=n;i++){
		dp[i][0]=min(dp[i-1][0]+abs(R[i]-L[i-1])+R[i]-L[i],dp[i-1][1]+abs(R[i]-R[i-1])+R[i]-L[i])+1;
		dp[i][1]=min(dp[i-1][0]+abs(L[i]-L[i-1])+R[i]-L[i],dp[i-1][1]+abs(L[i]-R[i-1])+R[i]-L[i])+1;
	}
	cout<<min(dp[n][0]+n-L[n],dp[n][1]+n-R[n]);
	return 0;	
}

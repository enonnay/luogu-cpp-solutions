#include <bits/stdc++.h>
using namespace std;
int t[1001][1001],dp[1001][1001],n,ans;



int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin >> t[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + t[i][j];
	for(int i=1;i<=n;i++)
		ans = max(dp[n][i],ans);
	
	cout<<ans;
	return 0;
	
}

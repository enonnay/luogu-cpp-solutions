#include <bits/stdc++.h>
using namespace std;
const int fx[]={0,2,2,1,1,-1,-1,-2,-2};
const int fy[]={0,1,-1,2,-2,2,-2,1,-1};
bool s[40][40];
long long dp[40][40];
int bx,by,mx,my;

int main(){
	cin>>bx>>by>>mx>>my;
	bx+=2;by+=2;mx+=2;my+=2;
	s[mx][my] = 1;
	dp[2][1] =1;
	for(int i=1;i<=8;i++){
		s[mx+fx[i]][my+fy[i]] = 1;
	}
	for(int i=2;i<=bx;i++)
		for(int j=2;j<=by;j++){
			if(s[i][j]) continue;
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	cout <<dp[bx][by];
	return 0;
}

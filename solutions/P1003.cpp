#include <bits/stdc++.h>
using namespace std;
int d[10005][10];
int n,x,y;
int ans = -1;

int main(){
	cin >>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=4;j++)
			cin>>d[i][j];
	cin >>x>>y;
	for(int i=n;i>0;i--){
		if((d[i][1]<=x)&&(x<=(d[i][1]+d[i][3]))&&(d[i][2]<=y)&&(y<=(d[i][2]+d[i][4]))){
			ans = i;
			break;
		}
	}
	cout <<ans;
	return 0;
}

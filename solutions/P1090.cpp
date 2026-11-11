#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int n,a,b,ans;

int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		int x;
		cin >>x;
		pq.push(x);
	}
	while(pq.size()>1){
		a=pq.top();pq.pop();
		b=pq.top();pq.pop();
		ans += a+b;
		pq.push(a+b);
	}
	cout<<ans;
	return 0;
}

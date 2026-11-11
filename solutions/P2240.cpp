#include <bits/stdc++.h>
using namespace std;
struct node{
	double w;
	double v;
	double p;
}a[105];
int n;
double sum,t;

inline bool cmp(node a,node b){
	return a.p > b.p;
}

int main(){
	cin >>n>>t;
	for(int i=1;i<=n;i++){
		cin >>a[i].w>>a[i].v;
		a[i].p = a[i].v/a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(t>=a[i].w){
			t-=a[i].w;
			sum += a[i].v;
		}
		else{
			sum += a[i].p * t;
			break;
		}
	}
	printf("%.2f",sum);
	return 0;
	
}

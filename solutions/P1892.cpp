#include <bits/stdc++.h>
using namespace std;
int n,m,f[2000],e[2000],cnt[2000],x,y,ans;
char opt;

int find1(int x){
	if(f[x]==x) return x;
	else return f[x] = find1(f[x]);
}

void hebing(int x,int y){
	f[find1(x)] = find1(y);
	return;
}

int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>opt>>x>>y;
		if(opt=='F') hebing(x,y);
		if(opt=='E'){
			if(e[x]==0) e[x] = find1(y);
			else hebing(e[x],y);
			if(e[y]==0) e[y] = find1(x);
			else hebing(e[y],x);
		}
	}
	for(int i=1;i<=n;i++) cnt[find1(i)]++;
	for(int i=1;i<=n;i++){
		if(cnt[i]) ans++;
	}
	cout<<ans;
	return 0;
}

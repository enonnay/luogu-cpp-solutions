#include <bits/stdc++.h>
using namespace std;
int n,m,fa[1000000],z,x,y;

int find1(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x] = find1(fa[x]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>z>>x>>y;
		if(z==1){
			fa[find1(x)] = find1(y);
		}
		if(z==2){
			if(find1(x)==find1(y)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
	return 0;
}


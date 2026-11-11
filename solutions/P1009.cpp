#include <bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100],d[100],n,lena=0,lenb=1,lenc=1,m;

int main(){
	cin >> n;
	b[1] = 1;
	for(int i=1;i<=n;i++){
		int p = i;
		lena =0;
		while(p>0){
			a[++lena] = p%10;
			p/=10;
		}
		for(int j=1;j<=lena;j++)
			for(int k=1;k<=lenb;k++){
				c[j+k-1] += a[j] * b[k];
			}
		lenc = lena + lenb;
		for(int j=1;j<=lenc;j++){
			c[j+1] += c[j] /10;
			c[j] %= 10;
		}
		while(c[lenc]==0 && lenc>1)
			lenc--;
		for(int j=1;j<=lenc;j++){
			b[j] = c[j];
		}
		lenb = lenc;
		memset(c,0,sizeof(c));
		m = max(m,lenc);
		for(int j=1;j<=m;j++){
			d[j] += b[j];
			d[j+1] += d[j]/10;
			d[j] %= 10;
		}
	}
	while(!d[m]&&m>1){
		m--;
	}
	for(int i=m;i>=1;i--){
		cout<<d[i];
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> a,b,n;

int main(){
	int x;
	while(cin>>x) n.push_back(x);
	for(int y:n){
		auto it = lower_bound(a.begin(),a.end(),y);
		if(it == a.end())
			a.push_back(y);
		else
			*it = y;
	}
	for(int z:n){
		auto it = upper_bound(b.begin(),b.end(),z,greater<int>());
		if(it == b.end())
			b.push_back(z);
		else
			*it = z;
	}
	cout<<b.size()<<endl;
	cout<<a.size()<<endl;
	return 0;
}


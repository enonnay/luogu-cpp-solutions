#include <bits/stdc++.h>
using namespace std;
unordered_set<int> x;
unordered_set<int> y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    int r,c;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>r>>c;
        x.insert(r);
        y.insert(c);
    }
    long long sizex = x.size();
    long long sizey = y.size();
    long long ans = n*sizex+n*sizey-sizex*sizey;
    cout<<ans;
    return 0;
}
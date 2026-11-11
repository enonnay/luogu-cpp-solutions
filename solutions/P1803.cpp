#include <bits/stdc++.h>
using namespace std;
int n,ns,ans;
struct Race{
    int sta;
    int sto;
};

bool cmp(Race &a,Race&b){
    if(a.sto!=b.sto) return a.sto<b.sto;
    return a.sta>b.sta;
}

int main(){
    cin >> n;
    vector<Race> r(n+1);
    for(int i=1;i<=n;i++){
        cin>>r[i].sta>>r[i].sto;
    }
    sort(r.begin()+1,r.end(),cmp);
    for(int i=1;i<=n;i++){
        if(ns<=r[i].sta){
            ans++;
            ns = r[i].sto;
        }
    }
    cout << ans;
    return 0;
}

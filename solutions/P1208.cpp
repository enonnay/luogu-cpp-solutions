#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
struct Farmer{
    int price;
    int milk;
};

bool cmp(Farmer &a,Farmer &b){
    return a.price<b.price;
}

int main(){
    Farmer f[5005];
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>f[i].price>>f[i].milk;
    }
    sort(f+1,f+m,cmp);
    for(int i=1;i<=m;i++){
        if(f[i].milk<n){
            ans += f[i].price*f[i].milk;
            n-=f[i].milk;
        }
        else{
            ans += f[i].price * n;
            break;
        }
    }
    cout << ans;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int k,l,li,r,ri,a[200];

int main(){
    cin>>k;
    int n=1;
    for(int i=1;i<=k;i++){
        n*=2;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n/2;i++){
        l = max(l,a[i]);
    }
    for(int i=1;i<=n/2;i++){
        if(a[i]==l){
            li = i;
        }
    }
    for(int j=n/2+1;j<=n;j++){
        r = max(r,a[j]);
    }
    for(int j=n/2+1;j<=n;j++){
        if(a[j]==r){
            ri = j;
        }
    }
    if(l>r){
        cout<<ri;
    }
    else{
        cout<<li;
    }
    return 0;
}
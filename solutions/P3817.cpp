#include <bits/stdc++.h>
using namespace std;
long long n,x,a[100005],ans;

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(i==1&&a[i]>x){
            ans+=a[i]-x;
            a[i]=x;
        }
        if(a[i]+a[i+1]>x){
            ans += a[i]+a[i+1]-x;   
            a[i+1] = x-a[i];
        }
    }
    cout<<ans;
    return 0;

}
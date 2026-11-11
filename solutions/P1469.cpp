#include <bits/stdc++.h>
using namespace std;
int n,len,ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len;
        ans^=len;
    }
    cout<<ans;
    return 0;
}
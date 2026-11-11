#include <bits/stdc++.h>
using namespace std;
int d[100005],n,ans;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=2;i<=n;i++){
        if(d[i]>d[i-1]){
            ans += d[i] - d[i-1];
        }
    }
    cout<<ans + d[1];
    return 0;

}
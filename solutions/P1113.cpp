#include <bits/stdc++.h>
using namespace std;
int finish[100005];

int main(){
    int n;
    int ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int w,t,a;
        cin>>w>>t;
        cin>>a;
        int max_prev = 0;
        while(a!=0){
            max_prev = max(max_prev,finish[a]);
            cin>>a;
        }
        finish[i] = max_prev+t;
    }
    for(int i=1;i<=n;i++){
        ans = max(ans,finish[i]);
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int num[1000005],cnt[1000005],ans[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        cnt[num[i]]++;
    }
    for(int i=1;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i){
            ans[j]+=cnt[i];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[num[i]]-1<<"\n";
    }
    return 0;
}
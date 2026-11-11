#include <bits/stdc++.h>
using namespace std;
long long n,x,cnt[5005],ans;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >>x;
        cnt[x]++;
    }
    for(int i=1;i<=5000;i++){
        if(!cnt[i]) continue;
        int l = i;
        for(int j=1;j<=l/2;j++){
            if(!cnt[j]) continue;
            int k = l-j;
            if(!cnt[k]) continue;
            if(j==k) ans = (ans + (cnt[i]*(cnt[i]-1)*cnt[j]*(cnt[j]-1))/4)% 1000000007;
            else ans = (ans + (cnt[i]*(cnt[i]-1)*cnt[j]*cnt[k])/2)% 1000000007;
        }
    }
    cout << ans;
    return 0;

}
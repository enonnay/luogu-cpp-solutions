#include <bits/stdc++.h>
using namespace std;
long long n,c,a[200005],ans;

int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ans += upper_bound(a+1,a+n+1,a[i]-c)-lower_bound(a+1,a+n+1,a[i]-c);
    }
    cout << ans;
    return 0;

}
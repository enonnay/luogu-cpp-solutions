#include <bits/stdc++.h>
using namespace std;
int n,cnt[100005],ans;
struct Passenger{
    int t;
    int x;
};

int main(){
    cin>>n;
    queue<Passenger> q;
    for(int i=1;i<=n;i++){
        int t,k;
        cin>>t>>k;
        for(int j=1;j<=k;j++){
            int x;
            Passenger p;
            cin>>x;
            p.x = x;
            p.t = t;
            q.push(p);
            if(cnt[x]==0){
                cnt[x]++;
                ans++;
            }
            else{
                cnt[x]++;
            }
            Passenger pf = q.front();
            while(p.t-pf.t>=86400){
                if(cnt[pf.x]==1){
                    cnt[pf.x]--;
                    ans--;
                    q.pop();
                    pf = q.front();
                }
                else{
                    cnt[pf.x]--;
                    q.pop();
                    pf = q.front();
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
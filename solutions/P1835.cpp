#include <bits/stdc++.h>
using namespace std;
bool isprime[50005],notprime[1000005];
int prime[50005],cnt;

void getprime(int n){
    memset(isprime,1,sizeof(isprime));
    isprime[1]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            prime[++cnt]=i;
        }
        for(int j=1;i*prime[j]<=n;j++){
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}

int main(){
    long long l,r,ans;
    cin>>l>>r;
    getprime(50000);
    for(int i=1;i<=cnt;i++){
        long long p = prime[i];
        if(p*p>r) break;
        long long start=max(2LL,(l+p-1)/p)*p;
        for(long long j=start;j<=r;j+=p){
            notprime[j-l]=1;
        }
    }
    if(l==1){
        notprime[0]=1;
    }
    ans=0;
    for(long long i=0;i<=r-l;i++){
        if(!notprime[i]) ans++;
    }
    cout<<ans;
    return 0;
}
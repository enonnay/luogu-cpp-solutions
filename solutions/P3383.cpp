#include <bits/stdc++.h>
using namespace std;
bool isprime[100000005];
int prime[6000000],cnt;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q,k;
    cin>>n>>q;
    getprime(n);
    for(int i=1;i<=q;i++){
        cin>>k;
        cout<<prime[k]<<"\n";
    }
    return 0;
}
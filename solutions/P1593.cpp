#include <bits/stdc++.h>
using namespace std;
const int MOD = 9901;
int a,b,cnt;
int ans=1;
int y[100001][2];

int qpow(int m,int n){
    int s=1;
    while(n>0){
        if(n%2==1){
            s=(s%MOD)*(m%MOD)%MOD;
        }
        m=m*m%MOD;
        n=n>>1;
    }
    return s;
}

int sum(int m,int n){
    int k=0;
    n*=b;
    if(m%MOD==1){
        return (n+1)%MOD;
    }
    else{
        k=(qpow(m%MOD,n+1)-1)%MOD*qpow((m-1)%MOD,MOD-2)%MOD;
    }
    return k%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b;
    if(a==0){
        cout<<"0\n";
        return 0;
    }
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            cnt++;
            y[cnt][0]=i;
            y[cnt][1]=1;
            a/=i;
            while(a%i==0){
                y[cnt][1]++;
                a/=i;
            }
        }
    }
    if(a!=1){
        cnt++;
        y[cnt][0]=a;
        y[cnt][1]=1;
    }
    for(int i=1;i<=cnt;i++){
        ans=(ans*sum(y[i][0],y[i][1]))%MOD;
    }
    cout<<(ans%MOD+MOD)%MOD;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a0,a1,b0,b1,ans,num1;
    cin>>n;
    for(int i=1;i<=n;i++){
        ans=0;
        cin>>a0>>a1>>b0>>b1;
        for(int num=1;num*num<=b1;num++){
            if(b1%num!=0) continue;
            num1=b1/num;
            if(gcd(num,a0)==a1&&lcm(num,b0)==b1){
                ans++;
            }
            if(gcd(num1,a0)==a1&&lcm(num1,b0)==b1&&num!=num1){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
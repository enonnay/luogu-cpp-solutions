#include <bits/stdc++.h>
using namespace std;
bool dig[32];

int main(){
    long long num,mid;
    int pos=0;
    cin>>num;
    while(num!=0){
        dig[pos]=num%2;
        pos++;
        num/=2;
    }
    for(int i=0;i<=15;i++){
        mid=dig[i];
        dig[i]=dig[i+16];
        dig[i+16]=mid;
    }
    long long pow=1;
    long long ans=0;
    for(int i=0;i<=31;i++){
        ans+=dig[i]*pow;
        pow*=2;
    }
    cout<<ans;
    return 0;
}
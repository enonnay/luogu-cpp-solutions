#include <bits/stdc++.h>
using namespace std;
long long x,y,ans;

int main(){
    cin >>x>>y;
    for(long long i=1;i<=sqrt(x*y);i++){
        if((x*y)%i==0&&__gcd(i,x*y/i)==x) ans+=2;
    }
    if(x==y) ans-=1;
    cout << ans;
}
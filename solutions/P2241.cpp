#include <bits/stdc++.h>
using namespace std;
long long n,m,zfx,cfx;

int main(){
    cin >>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(i==j) zfx+=(n-i)*(m-j);
            else cfx +=(n-i)*(m-j);
    cout<<zfx<<" "<<cfx;
    return 0;
}
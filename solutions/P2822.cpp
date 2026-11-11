#include <bits/stdc++.h>
using namespace std;
const int MAXN=2000;
int c[MAXN+5][MAXN+5];
int s[MAXN+5][MAXN+5];

void init(int k){
    c[0][0]=1;
    for(int i=1;i<=MAXN;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
        }
    }
    for(int i=1;i<=MAXN;i++){
        for(int j=1;j<=MAXN;j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(j<=i&&c[i][j]==0){
                s[i][j]++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,k,n,m;
    cin>>t>>k;
    init(k);
    for(int i=1;i<=t;i++){
        cin>>n>>m;
        if(m>n) m=n;
        cout<<s[n][m]<<"\n";
    }
    return 0;
}

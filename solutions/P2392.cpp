#include <bits/stdc++.h>
using namespace std;
int a[5],b[5][25],f[25][605],ans;

int dp(int id){
    memset(f,0,sizeof(f));
    int sum = 0;
    for(int i=1;i<=a[id];i++) sum+=b[id][i];
    int target = sum/2;

    for(int i=1;i<=a[id];i++){
        for(int j=1;j<=target;j++){
            if(j<b[id][i]){
                f[i][j] = f[i-1][j];
            }
            else{
                f[i][j] = max(f[i-1][j],(f[i-1][j-b[id][i]]+b[id][i]));
            }
        }
    }
    return sum-f[a[id]][target];
}

int main(){
    for(int i=1;i<=4;i++){
        cin>>a[i];
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=a[i];j++){
            cin >>b[i][j];
        }
        ans += dp(i);
    }
    cout<<ans;
    return 0;
}
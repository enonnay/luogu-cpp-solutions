#include <bits/stdc++.h>
using namespace std;
int n;
double x[20],y[20];
double ans = 1e16;
double dist[20][20];
double dp[1<<16][20];

double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x[i] >>y[i]; //预处理距离
    }

    for(int i=1;i<(1<<n);i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = 1e16; //初始化dp数组，距离为无穷大

    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dist[i][j] = dis(x[i],y[i],x[j],y[j]);

    for(int i=1;i<=n;i++)
        dp[1<<(i-1)][i] = dist[0][i];
    
    for(int m=1;m<(1<<n);m++){
        for(int i=1;i<=n;i++){  
            if(!(m&(1<<(i-1)))) continue;
            if(dp[m][i]>=1e16) continue;
            for(int j=1;j<=n;j++){
                if(!(m&(1<<(j-1)))){
                    int newm = m | (1<<(j-1));
                    dp[newm][j] = min(dp[newm][j],dp[m][i]+dist[i][j]);
                }
            }
        }
    }

    int finally = (1<<n)- 1;
    for(int i=1;i<=n;i++){
        ans = min(ans,dp[finally][i]);
    }
    printf("%.2f",ans);
    return 0;
}

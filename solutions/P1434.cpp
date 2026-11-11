#include <bits/stdc++.h>
using namespace std;
int r,c,m[105][105],memo[105][105],ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int row,int col){
    if(memo[row][col]!=0){
        return memo[row][col];
    }
    int maxlen = 1;
    for(int i=0;i<=3;i++){
        int nx = row+dx[i];
        int ny = col+dy[i];
        if(nx>0&&nx<=r&&ny>0&&ny<=c&&m[nx][ny]<m[row][col]){
            maxlen = max(maxlen,dfs(nx,ny)+1);
        }
    }
    memo[row][col] = maxlen;
    return maxlen;
}

int main(){
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> m[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ans  = max(ans,dfs(i,j));
        }
    }
    cout<<ans;
    return 0;

}
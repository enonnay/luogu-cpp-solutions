#include <bits/stdc++.h>
using namespace std;
int m,a[305][305],b[305][305],danger[305][305];
queue<pair<int,int>> q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    cin >> m;
    memset(a,-1,sizeof(a));
    memset(danger,0x3f,sizeof(danger));
    for(int i=1;i<=m;i++){
        int x,y,t;
        cin >>x>>y>>t;
        b[x][y] = t;
        danger[x][y] = min(t,danger[x][y]);
        for(int j=0;j<=3;j++){
            if(x+dx[j]>=0&&y+dy[j]>=0){
            danger[x+dx[j]][y+dy[j]] = min(t,danger[x+dx[j]][y+dy[j]]);
            }
        }
    }
    a[0][0] = 0;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        if(danger[x1][y1]>1005){
            cout<<a[x1][y1];
            return 0;
        }
        for(int i=0;i<=3;i++){
            int px = x1+dx[i];
            int py = y1+dy[i];
            if(px>=0&&px<302&&py>=0&&py<302&&a[px][py]==-1&&(a[x1][y1]+1<danger[px][py])){
                a[px][py] = a[x1][y1] + 1;
                q.push(make_pair(px,py));
            }
        }
    }
    cout <<-1;
    return 0;

}
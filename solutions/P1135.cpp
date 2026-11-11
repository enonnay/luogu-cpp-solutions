#include <bits/stdc++.h>
using namespace std;
int n,a,b,p[205],dis[205];
queue<int> q;

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        dis[i] = -1;
    }
    q.push(a);
    dis[a] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x+p[x]<=n&&dis[x+p[x]]==-1){
            dis[x+p[x]] = dis[x] + 1;
            q.push(x+p[x]);
        }
        if(x-p[x]>0&&dis[x-p[x]]==-1){
            dis[x-p[x]] = dis[x] + 1;
            q.push(x-p[x]);
        }
    }
    cout << dis[b];
    return 0;

}
#include <bits/stdc++.h>
using namespace std;
int n,col[20],cnt;
bool pos[40],xjay[40],xjiany[40];
void dfs(int x){
    if(x>n){
        cnt++;
        if(cnt<=3){
            for(int i=1;i<=n;i++) cout<<col[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(pos[i]==0&&xjay[i+x]==0&&xjiany[x-i+n]==0){
            pos[i]=1;
            xjay[i+x]=1;
            xjiany[x-i+n]=1;
            col[x] = i;
            dfs(x+1);
            pos[i]=0;
            xjay[i+x]=0;
            xjiany[x-i+n]=0;
        }
    }
}

int main(){
    cin >> n;
    dfs(1);
    cout << cnt;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int in[5005],out[5005],num[5005],ans;

int main(){
    queue<int> q;
    vector<int> t[5005];
    int m,n,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        out[a]++;
        in[b]++;
        t[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!in[i]){
            num[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int tot = q.front();
        q.pop();
        int len = t[tot].size();
        for(int i=0;i<len;i++){
            int nex = t[tot][i];
            in[nex]--;
            num[nex]=(num[tot]+num[nex])%80112002;
            if(in[nex]==0) q.push(nex);
        }
    }
    for(int i=1;i<=n;i++){
        if(!out[i]){
            ans=(ans+num[i])%80112002;
        }
    }
    cout<<ans;
    return 0;
}
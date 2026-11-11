#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int fa[MAXN];

int find1(int x){
    if(fa[x]==x) return x;
    else{
        return fa[x]=find1(fa[x]);
    }
}

int main(){
    int n,m,a,b,ans;
    set<int> fathers;
    while(cin>>n&&n!=0){
        cin>>m;
        ans = 0;
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            int seta = find1(a);
            int setb = find1(b);
            fa[setb] = seta;
        }
        for(int i=1;i<=n;i++){
            if(fa[i]==i){
                ans++;
            }
        }
        ans-=1;
        cout<<ans<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct Treenode{
    int l;
    int r;
}tree[1000005];
int maxdepth;

void dfs(int a,int depth){
    if(tree[a].l==0&&tree[a].r==0) return;
    maxdepth = max(maxdepth,depth+1);
    dfs(tree[a].l,depth+1);
    dfs(tree[a].r,depth+1);
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    dfs(1,1);
    cout<<maxdepth;
    return 0;
}
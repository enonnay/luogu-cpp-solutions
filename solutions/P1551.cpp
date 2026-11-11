#include <bits/stdc++.h>
using namespace std;
int fa[5005];

int find1(int x){
    if(fa[x]==x){
        return x;
    }
    else{
        return fa[x]=find1(fa[x]);
    }
}

int main(){
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        fa[find1(b)]=fa[find1(a)];
    }
    for(int i=1;i<=p;i++){
        int c,d;
        cin>>c>>d;
        if(find1(c)==find1(d)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
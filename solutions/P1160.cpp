#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int l[100005],r[100005];
bool deleted[100005];

void insert_right(int k,int x){
    r[x] = r[k];
    l[x] = k;
    l[r[k]] = x;
    r[k] = x;
}

void deletex(int x){
    if(deleted[x]) return;
    r[l[x]] = r[x];
    l[r[x]] = l[x];
    deleted[x] = 1;
}

int main(){
    cin>>n;
    r[0]=1;
    l[1]=0;
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        if(p==1){
            insert_right(k,i);
        }
        else{
            insert_right(l[k],i);
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        deletex(x);
    }

    for(int i=r[0];i!=0;i=r[i]){
        cout<<i<<" ";
    }

    return 0;
}
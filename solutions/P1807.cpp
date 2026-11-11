#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;
int head[MAXN],to[MAXN],weight[MAXN],nxt[MAXN],edgecnt,dist[MAXN];
bool inq[MAXN];
queue<int> q;

void addedge(int u,int v,int w){
    to[edgecnt]=v;
    weight[edgecnt]=w;
    nxt[edgecnt]=head[u];
    head[u]=edgecnt++;
}

int main(){
    int n,m,u,v,w;
    memset(head,-1,sizeof(head));
    memset(dist,0x3f,sizeof(dist));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        addedge(u,v,-w);
    }
    dist[1]=0;
    q.push(1);
    inq[1]=true;
    while(!q.empty()){
        u = q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i!=-1;i=nxt[i]){
            int v=to[i];
            int w=weight[i];
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!inq[v]){
                q.push(v);
                inq[v]=true;
            }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f){
        cout<<-1<<endl;
    }
    else{
        cout<<-dist[n]<<endl;
    }
    return 0;
}
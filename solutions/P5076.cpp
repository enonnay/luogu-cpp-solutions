#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int tot,root;
struct Node{
    int left,right,size,value,num;
    Node(int l,int r,int s,int v):left(l),right(r),size(s),value(v),num(1){};
    Node(){};
}t[MAXN];

inline void update(int root){
    t[root].size = t[t[root].left].size+t[t[root].right].size+t[root].num;
}

int ran(int x,int root){
    if(root){
        if(x<t[root].value){
            return ran(x,t[root].left);
        }
        if(x>t[root].value){
            return ran(x,t[root].right)+t[t[root].left].size+t[root].num;
        }
        return t[t[root].left].size+1;
    }
    return 1;
}

int ranker(int x,int root){
    if(root){
        if(x<=t[t[root].left].size){
            return ranker(x,t[root].left);
        }
        if(x>t[t[root].left].size+t[root].num){
            return ranker(x-t[t[root].left].size-t[root].num,t[root].right);
        }
        return t[root].value;
    }
    return 0;
}

int inf(int x,int root){
    int ans = -2147483647;
    while(root){
        if(t[root].value<x){
            ans = t[root].value;
            root = t[root].right;
        }
        else{
            root = t[root].left;
        }
    }
    return ans;
}

int sup(int x,int root){
    int ans = 2147483647;
    while(root){
        if(t[root].value>x){
            ans = t[root].value;
            root = t[root].left;
        }
        else{
            root = t[root].right;
        }
    }
    return ans;
}

void ins(int x,int &root){
    if(!root){
        root = ++tot;
        t[root].value = x;
        t[root].left = t[root].right = 0;
        t[root].num = 1;
        t[root].size = 1;
        return;
    }
    if(x<t[root].value){
        ins(x,t[root].left);
    }
    if(x>t[root].value){
        ins(x,t[root].right);
    }
    update(root);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int op,x;
        cin>>op>>x;
        if(op==1){
            cout<<ran(x,root)<<endl;
        }
        if(op==2){
            cout<<ranker(x,root)<<endl;
        }
        if(op==3){
            cout<<inf(x,root)<<endl;
        }
        if(op==4){
            cout<<sup(x,root)<<endl;
        }
        if(op==5){
            ins(x,root);
        }
    }
    return 0;
}
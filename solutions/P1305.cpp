#include <bits/stdc++.h>
using namespace std;

struct Node{
    int root;
    int left;
    int right;
}t[30];

void bianli(int root){
    char ch = 'a'+root-1;
    cout<<ch;
    if(t[root].left){
        bianli(t[root].left);
    }
    if(t[root].right){
        bianli(t[root].right);
    }
}

int main(){
    int n,root;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        if(i==1){
            root = a-'a'+1;
        }
        if(b!='*'){
            t[a-'a'+1].left=b-'a'+1;
        }
        if(c!='*'){
            t[a-'a'+1].right=c-'a'+1;
        }
    }
    bianli(root);
    return 0;
}
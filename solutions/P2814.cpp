#include <bits/stdc++.h>
using namespace std;
int fa[50005],idx;
string id2name[50005];
unordered_map<string,int> name2id;

int findid(int x){
    return fa[x]==x?x:fa[x]=findid(fa[x]);
}

int getid(string s){
    auto it = name2id.find(s);
    if(it==name2id.end()){
        idx++;
        name2id[s]=idx;
        id2name[idx]=s;
        fa[idx]=idx;
        return idx;
    }
    else{
        return it->second;    
    }
}

int main(){
    char op;
    string name;
    int cur_father;
    while(cin>>op&&op!='$'){
        cin>>name;
        int id = getid(name);
        if(op=='#'){
            cur_father = id;
        }
        else if(op=='+'){
            int rootfa=findid(cur_father);
            int rootson=findid(id);
            if(rootfa!=rootson){
                fa[rootson]=rootfa;
            }
        }
        else if(op=='?'){
            cout<<name<<" "<<id2name[findid(id)]<<endl;
        }
    }
    return 0;
}
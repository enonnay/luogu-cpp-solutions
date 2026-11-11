#include <bits/stdc++.h>
using namespace std;
int idx;
string ans[100005];
int last[100005];
map<string,int> string2id;

int getid(string s){
    auto it = string2id.find(s);
    if(it==string2id.end()){
        idx++;
        string2id[s]=idx;
        return idx;
    }
    return it->second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l,m,id;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l;
        for(int j=1;j<=l;j++){
            cin>>s;
            id = getid(s);
            if(last[id]!=i){
                last[id]=i;
                ans[id].append(to_string(i)+" ");
            }
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>s;
        id = getid(s);
        cout<<ans[getid(s)];
        cout<<"\n";
    }
    return 0;
}

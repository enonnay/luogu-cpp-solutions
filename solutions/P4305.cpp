#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int,bool> s;
    int t,n,x;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        s.clear();
        for(int i=1;i<=n;i++){
            cin>>x;
            if(!s[x]){
                cout<<x<<" ";
                s[x]=1;
            }
        }
        cout<<"\n";
    }
    return 0;
}
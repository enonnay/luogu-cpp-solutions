#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> m;
int n,q;

int main(){
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        int c,a,b,k;
        cin>>c;
        if(c==1){
            cin>>a>>b>>k;
            m[{a,b}] = k;
        }
        else if(c==2){
            cin>>a>>b;
            cout << m[{a,b}]<<endl;
        }

    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int q,pushed[100005],poped[100005];
int main(){
    cin>>q;
    for(int i=1;i<=q;i++){
        stack<int> s;
        int n;
        int idx = 1;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>pushed[j];
        }
        for(int j=1;j<=n;j++){
            cin>>poped[j];
        }
        for(int j=1;j<=n;j++){
            if(pushed[j]==poped[idx]){
                idx++;
            }
            else{
                s.push(pushed[j]);
            }
            while(!s.empty()&&s.top()==poped[idx]){
                    s.pop();
                    idx++;
                }
        }
        for(int j=idx;j<=n;j++){
            if(!s.empty()&&s.top()==poped[idx]){
                idx++;
                s.pop();
            }
            else{
                break;
            }
        }
        if(!s.empty()){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
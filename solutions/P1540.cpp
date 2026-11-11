#include <bits/stdc++.h>
using namespace std;
int m,n,t,ans;
deque<int> memo;

bool find(int x){
    for(auto it = memo.begin();it!=memo.end();it++){
        if(*it == x) return 1;
    }
    return 0;
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        if(find(num)){
            continue;
        }
        else{
            ans++;
            if(t<m){
                memo.push_back(num);
                t++;
            }
            else{
                memo.pop_front();
                memo.push_back(num);
            }
        }
    }
    cout<<ans;
    return 0;
}
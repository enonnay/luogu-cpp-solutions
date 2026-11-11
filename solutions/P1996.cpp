#include <bits/stdc++.h>
using namespace std;
int n,m;
queue<int> q;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;

}
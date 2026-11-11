#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> path;

void dfs(int a,int b){
    for(int i=b;i<=a/2;i++){
        path.push_back(i);
        dfs(a-i,i);
        path.pop_back();
    }
    
    if(!path.empty()&&a>=b){
        for(int x:path){
            cout<<x<<'+';
        }
        cout<<a<<endl;
    }

}
int main(){
    cin >> n;
    dfs(n,1);
    return 0;
}
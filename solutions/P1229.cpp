#include <bits/stdc++.h>
using namespace std;
string a,b;
int po;

int main(){
    cin>>a>>b;
    for(int i=0;i+1<(int)a.size();i++){
        for(int j=1;j<(int)b.size();j++){
            if(a[i]==b[j]&&a[i+1]==b[j-1]){
                po++;
            }
        }
    }
    long long ans = 1;
    for(int i=1;i<=po;i++){
        ans*=2;
    }
    cout<<ans;
    return 0;
}
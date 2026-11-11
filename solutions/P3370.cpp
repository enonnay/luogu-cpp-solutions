#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull b=131;
ull a[10005];

ull gethash(string &s){
    ull h=0;
    for(int i=0;i<s.length();i++){
        h=h*b+s[i];
    }
    return h;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a[i]=gethash(s);
    }
    sort(a+1,a+n+1);
    cout<<unique(a+1,a+n+1)-a-1;
    return 0;
}

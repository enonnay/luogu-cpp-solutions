#include <bits/stdc++.h>
using namespace std;

void work(string mid,string bk){
    if(mid.size()<=0) return;
    char u = bk[bk.size()-1];
    int k = mid.find(u);
    string m1 = mid.substr(0,k);
    string m2 = mid.substr(k+1);
    string bk1 = bk.substr(0,k);
    string bk2 = bk.substr(k, mid.size() - k - 1);
    cout<<u;
    work(m1,bk1);
    work(m2,bk2);
}

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    work(a,b);
    return 0;
}

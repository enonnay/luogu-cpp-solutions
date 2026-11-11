#include <bits/stdc++.h>
using namespace std;
vector<int> a;
long long b;
string sa;

vector<int> div(vector<int> &a,long long &b){
    vector<int> c;
    long long r=0;
    for(int i=(int)a.size()-1;i>=0;i--){
        r = r*10+a[i];
        c.push_back(r/b);
        r%=b;
    }
    reverse(c.begin(),c.end());
    while(c.size()>1&&c.back()==0) c.pop_back();
    return c;
}

int main(){
    cin>>sa>>b;
    for(int i=sa.size()-1;i>=0;i--){
        a.push_back(sa[i]-'0');
    }
    vector<int> ans = div(a,b);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}

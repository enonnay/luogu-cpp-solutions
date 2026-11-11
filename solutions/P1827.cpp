#include <bits/stdc++.h>
using namespace std;
string lef,mid;

void work(string m,string l){
    if(l.empty()) return;
    char root = l[0];
    l.erase(l.begin());
    int k = m.find(root);
    string lm = m.substr(0,k);
    string rm = m.substr(k+1);
    string ll = l.substr(0,k);
    string rl = l.substr(k);
    work(lm,ll);
    work(rm,rl);
    cout<<root;
}

int main(){
    cin>>mid>>lef;
    work(mid,lef);
    return 0;
}

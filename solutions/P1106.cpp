#include <bits/stdc++.h>
using namespace std;
int k;
string n;
int top = 0;

int main(){
    string stk = "";
    cin>>n>>k;
    for(char c:n){
        while(!stk.empty()&&k>0&&stk.back()>c){
            stk.pop_back();
            k--;
        }
        stk.push_back(c);
    }
    while(k>0&&!stk.empty()){
        stk.pop_back();
        k--;
    }
    int start = 0;
    while(start<(int)stk.size()&&stk[start]=='0'){
        start++;
    }
    if(start==(int)stk.size()){
        cout<<'0';
        return 0;
    }
    for(int i=start;i<(int)stk.size();i++){
        cout<<stk[i];
    }
    return 0;

}
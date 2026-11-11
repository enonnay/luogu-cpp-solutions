#include <bits/stdc++.h>
using namespace std;
int ans;

int main(){
    int last=-10;
    string s;
    char c;
    cin>>s;
    if(s.length()>6){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.length();i++){
        c=s[i];
        if(c>='a'&&c<='z'){
            if(c-'a'+1<=last){
                cout<<0;
                return 0;
            }
            last=c-'a'+1;
            ans = ans*(26-i+1)+last-i;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
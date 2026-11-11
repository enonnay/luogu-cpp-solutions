#include <bits/stdc++.h>
using namespace std;
string s;
bool a[105];

int main(){
    cin>>s;
    string ans = s;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(c=='['||c=='('){
            continue;
        }
        else if(c==']'){
            for(int j=i-1;j>=0;j--){
                if(s[j]=='('&&!a[j]){
                    break;
                }
                else if(s[j]=='['&&!a[j]){
                    a[j]=1;
                    a[i]=1;
                    break;
                }
            }
        }
        else if(c==')'){
            for(int j=i-1;j>=0;j--){
                if(s[j]=='['&&!a[j]){
                    break;
                }
                else if(s[j]=='('&&!a[j]){
                    a[j]=1;
                    a[i]=1;
                    break;
                }
            }
        }
    }
    int dif = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('&&!a[i]){
            ans.insert(i+1+dif,")");
            dif++;
        }
        if(s[i]=='['&&!a[i]){
            ans.insert(i+1+dif,"]");
            dif++;
        }
        if(s[i]==')'&&!a[i]){
            ans.insert(i+dif,"(");
            dif++;
        }
        if(s[i]==']'&&!a[i]){
            ans.insert(i+dif,"[");
            dif++;
        }
    }
    cout<<ans;
    return 0;
}
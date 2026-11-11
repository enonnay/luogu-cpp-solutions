#include <bits/stdc++.h>
using namespace std;
int n,ten,m,dig;
string num,ans;

int main(){
    int pow=1;
    cin>>n>>num>>m;
    for(int i=num.length()-1;i>=0;i--){
        if(num[i]>='0'&&num[i]<='9'){
            ten+=pow*(num[i]-'0');
        }
        else{
            ten+=pow*(num[i]-'A'+10);
        }
        pow*=n;
    }
    while(ten!=0){
        dig=ten%m;
        if(dig>=0&&dig<=9){
            ans=to_string(dig)+ans;
        }
        else{
            char c = 'A';
            c+=dig-10;
            ans=c+ans;
        }
        ten/=m;
    }
    cout<<ans;
    return 0;
}
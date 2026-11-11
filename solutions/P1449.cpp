#include <bits/stdc++.h>
using namespace std;
string c;

int main(){
    stack<int> s;
    cin>>c;
    int p=0;
    for(int i=0;i<c.length();i++){
        char k = c[i];
        if(k=='@') break;
        if(k>='0'&&k<='9'){
            p = 10*p+(k-'0');
        }
        else if(k == '.'){
            s.push(p);
            p = 0;
        }
        else if(k=='+'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a+b);
        }
        else if(k=='-'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b-a);
        }
        else if(k=='/'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b/a);
        }
        else if(k=='*'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a*b);
        }
    }
    cout << s.top()<<endl;
    return 0;
}
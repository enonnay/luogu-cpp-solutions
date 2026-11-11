#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    set<int> s;
    cin>>m;
    for(int i=1;i<=m;i++){
        int ctr,len;
        cin>>ctr>>len;
        if(ctr==1){
            if(s.count(len)){
                cout<<"Already Exist"<<endl;
            }
            else{
                s.insert(len);
            }
        }
        else{
            if(s.empty()){
                cout<<"Empty"<<endl;
            }
            else{
                auto it = s.lower_bound(len);
                if(it==s.begin()){
                    cout<<*it<<endl;
                    s.erase(it);
                }
                else if(it==s.end()){
                    --it;
                    cout<<*it<<endl;
                    s.erase(it);
                }
                else{
                    int diffprev = len-*prev(it);
                    int diffcur = *it-len;
                    if(diffprev<=diffcur){
                        cout<<*prev(it)<<endl;
                        s.erase(prev(it));
                    }
                    else{
                        cout<<*it<<endl;
                        s.erase(it);
                    }
                }
            }
        }
    }
    return 0;
}

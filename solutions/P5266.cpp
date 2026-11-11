#include <bits/stdc++.h>
using namespace std;

int main(){
    int q,op,score;
    string name;
    map<string,int> info;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            cin>>name>>score;
            if(info.find(name)==info.end()){
                info.insert({name,score});
            }
            else{
                info[name]=score;
            }
            cout<<"OK"<<endl;
        }
        else if(op==2){
            cin>>name;
            auto it = info.find(name);
            if(it==info.end()){
                cout<<"Not found"<<endl;
            }
            else{
                cout<<it->second<<endl;
            }
        }
        else if(op==3){
            cin>>name;
            auto it = info.find(name);
            if(it==info.end()){
                cout<<"Not found"<<endl;
            }
            else{
                info.erase(it);
                cout<<"Deleted successfully"<<endl;
            }
        }
        else if(op==4){
            int cnt=0;
            for(auto it=info.begin();it!=info.end();it++){
                cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
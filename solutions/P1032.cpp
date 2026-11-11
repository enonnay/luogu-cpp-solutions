#include <bits/stdc++.h>
using namespace std;
queue<pair<string,int>> q;
string a,b;
string ra[7],rb[7];

int main(){
    cin>>a>>b;
    int k = 1;
    while(cin>>ra[k]>>rb[k]){
        k++;
    }

    q.push(make_pair(a,0));

    while(!q.empty()){
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();
        if(step >= 10) continue;
        for(int i=1;i<k;i++){
            int pos = 0;
            while((pos=cur.find(ra[i],pos))!=-1){
                string next_str = cur.substr(0,pos) + rb[i] + cur.substr(pos+ra[i].length());
                if(next_str==b){
                    cout<<step+1;
                    return 0;
                }
                q.push(make_pair(next_str,step+1));
                pos++;
            }
        }
    }
    cout << "NO ANSWER!";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
char s[105][105];
bool b[105][105];
int dx[8] = {1,1,1,0,-1,-1,-1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
string target = "yizhong";
queue<pair<int,int>> q;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> s[i][j];
            if(s[i][j]=='y') q.push(make_pair(i,j));
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            for(int j=1;j<=6;j++){
                if(s[x+j*dx[i]][y+j*dy[i]]!=target[j]) break;
                if(j==6){
                    for(int k=0;k<=6;k++){
                        b[x+k*dx[i]][y+k*dy[i]] = 1;
                    }

            }
        }

    }
}

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==1){
                cout<<s[i][j];
            }
            else{
                cout<<'*';
            }
        }
        cout<<endl;
    }
    return 0;
}
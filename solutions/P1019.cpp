#include <bits/stdc++.h>
using namespace std;
int n,vis[30],f[30][30],cur_len,ans;
string words[30];
char head;


int overlap(string a,string b){
    int maxx = min(a.length(),b.length()) - 1;
    for(int i=1;i<=maxx;i++){
        if(a.substr(a.length()-i)==b.substr(0,i)){
            return i;
        }
    }
    return 0;
}

void dfs(int a){
    ans = max(ans,cur_len);
    for(int i=1;i<=n;i++){
        if(f[a][i]>0&&vis[i]<2){
            vis[i]++;
            cur_len += words[i].length() - f[a][i];
            dfs(i);
            vis[i]--;
            cur_len -= words[i].length() - f[a][i];
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> words[i];
    cin >> head;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j] = overlap(words[i],words[j]);
    for(int i=1;i<=n;i++){
        if(words[i][0] == head){
            vis[i]++;
            cur_len += words[i].length();
            dfs(i);
            cur_len -= words[i].length();
            vis[i]--;
        }
    }
    cout << ans;
    return 0;
}
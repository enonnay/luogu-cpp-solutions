#include <bits/stdc++.h>
using namespace std;
int l,n,m,a[50005];

int main(){
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=l;
    int left=1;
    int right=l;
    while(left<right){
        int last = 0;
        int mid = (left+right+1)/2;
        int d = 0;
        for(int i=1;i<=n+1;i++){
            if((a[i]-a[last])<mid){
                d++;
        }
        else{
            last = i;
        }
    }
        if(d>m){
            right = mid-1;
        }
        else{
            left = mid;
        }
    }
    cout<<left;
    return 0;
}
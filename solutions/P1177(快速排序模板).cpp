#include <bits/stdc++.h>
using namespace std;

int a[100005],n;

void qsort(int l,int r){
    if(l>=r) return;
    int i=l,j=r,x=a[rand()%(r-l+1)+l];
    while(i<=j){
        while(a[i]<x)i++;
        while(a[j]>x)j--;
        if(i<=j)swap(a[i++],a[j--]);
    }
    qsort(l,j);
    qsort(i,r);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long n,sum;
double ans;
struct Person{
    int id;
    int t;
};

bool cmp(Person &a,Person &b){
    if(a.t!=b.t) return a.t<b.t;
    return a.id<b.id;
}

int main(){
    cin >> n;
    vector<Person> p(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i].t;
        p[i].id = i;
    }
    sort(p.begin()+1,p.end(),cmp);
    for(int i=1;i<=n;i++){
        cout<<p[i].id<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        sum += p[i].t * (n-i);
    }
    ans = (double)sum/n;
    printf("%.2f",ans);
    return 0;

}
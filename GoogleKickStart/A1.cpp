#include<bits/stdc++.h>

using namespace std;

void func(int tt){
    cout<<"Case #"<<tt<<": ";
    int n, cost;
    cin>>n>>cost;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int i=0;
    while(i<n && cost >= a[i]){
        cost -= a[i++];
    }
    cout<<i<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        func(i);
    }
}
/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
#define mp           make_pair
#define pb           push_back
#define fi           first
#define si           second
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll tt;
	cin>>tt;
	while(tt--){
		string st;
		cin>>st;
		stack<ll> s;
		ll q, n = st.length();
		vector<ll> ans(n, -1);
		for(ll i=n-1; i>=0; i--){
			if(st[i] == ')'){
				s.push(i);
				if(i!=n-1 && ans[i+1] != -1){
					ans[i] = ans[i+1];
				}
			}
			else{
				if(s.empty()){
					ans[i] = -1;
				}
				if(!s.empty()){
					ans[i] = s.top()+1;
					s.pop();
				}
			}
		}
		cin>>q;
		while(q--){
			ll t;
			cin>>t;
			cout<<ans[t-1]<<"\n";
		}
	}
}
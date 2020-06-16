/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;


int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n, m;
	string p;
	cin>>n>>m;
	cin>>p;
	set<ll> pos;
	for(ll i=0; i<m; i++){
		ll temp;
		cin>>temp;
		pos.insert(temp);
	}
	string s;
	for(ll i=0; i<n; i++){ s.pb('?'); }
	for(auto it=pos.begin(); it!=pos.end(); it++){
		ll x = *it-1;;
		for(ll i=0; i<p.length(); i++){
			if(x+i >= n || (s[x+i] != '?' && s[x+i] != p[i]) ){
				cout<<0;
				return 0;
			}
			s[x+i] = p[i];
		}
	}
	ll pow=0;
	for(ll i=0; i<n; i++){
		pow += (s[i] == '?');
	}
	ll res=1, a = 26;
	while(pow){
		if(pow&1){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		pow = pow>>1;
	}
	cout<<res;
}
/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define vi 			 vector<int>
#define pb           push_back
#define fi           first
#define si           second
#define pii 		 pair<int,int>
#define vii 		 vector<pair<int,int>>
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)     memset(a, b, sizeof a)
#define matrix(x) 	 vector<vector<x>>
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j];}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	ll n, m, q;
	cin>>n>>m;
	string s[n];
	vector<vector<ll>> a(n+1, vector<ll>(m+1, 0));
	F(s, n);
	cin>>q;
	while(q--){
		ll lx, ly, rx, ry;
		cin>>lx>>ly>>rx>>ry;
		lx--;ly--;rx--;ry--;
		a[lx][ly]++;a[lx][ry+1]--;
		a[rx+1][ly]--;a[rx+1][ry+1]--;
	}
	for(int i=0; i<n; i++){
		ll ct=0;
		for(int j=0; j<m; j++){
			a[i][j] += ct;
			ct = a[i][j];
		}
	}
	for(int j=0; j<m; j++){
		ll ct=0;
		for(int i=0; i<n; i++){
			a[i][j] += ct;
			ct = a[i][j];
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]&1){
				if(s[i][j] == '1'){s[i][j]='0';}
				else{s[i][j]='1';}
			}
		}
	}
	PNF(s, n, m);
}
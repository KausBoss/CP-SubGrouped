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
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
ll bb = 0;

ll funk(ll pos, ll num, vector<ll> B){
	if(pos == -1){
		return 0;
	}
	if( ((num>>pos)&1)==1 && ((bb>>pos)&1) == 0){
		vector<ll> zero, one;
		for(int i=0; i<B.size(); i++){
			if( ((B[i]>>pos)&1) == 1){one.pb(B[i]);}
			else {zero.pb(B[i]);}
		}
		if(zero.size() != 0){
			return funk(pos-1, num, zero);
		}
		return (1<<pos)|funk(pos-1, num, B);
	}
	else{
		return (1<<pos)|funk(pos-1, num, B);
	}
}


void gggg(){
	ll n, m;
	cin>>n>>m;
	ll *a = new ll[n];
	F(a, n);
	sort(a, a+n);
	ll temp=0;
	for(int i=0; i<n; i++){
		temp |= a[i];
	}
	vector<ll> B(m);
	F(B, m);
	ll sm = temp;
	for(int i=0; i<m; i++){
		if((temp&B[i]) < sm){
			sm = temp&B[i];
		} 
	}
	cout<<sm;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;//cin>>t;
	while(t--){
		gggg();
	}
}
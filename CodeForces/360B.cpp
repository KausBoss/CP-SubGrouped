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
ll n, k;
ll a[2001];

bool Possile(ll x){
	ll dp[2001]={0};
	for(ll i=1; i<n; i++){
		for(ll j=0; j<i; j++){
			if(abs(a[i]-a[j]) <= (i-j)*x){
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
	}
	ll max_transactions=0;
	for(ll i =0; i<n; i++){
		max_transactions = max(max_transactions, dp[i]);
	}
	ll min_transactions = (n-1) - max_transactions;
	return min_transactions <= k;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin>>n>>k;
	F(a, n);
	ll s=0, e=2e9;// 30 Iterations approx

	while(s <= e){
		ll mid = (s+e)/2;
		if(Possile(mid)){
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	cout<<s;
}
/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
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
const int nax = 2e7;
const int mod = 1e9+7;
ll a[2001], b[2001], n, m;
ll dp[2001][2001][6];

ll func(ll i, ll j, ll k){
	//base case
	if(i==n || j==m){
		return 0;
	}
	//recursive case
	if(dp[i][j][k] != -1){return dp[i][j][k];}

	if(a[i] == b[j]){
		return 1 + func(i+1, j+1, k);
	}
	ll op1 = func(i+1, j, k);
	ll op2 = func(i, j+1, k);
	if(k>0){
		op2 = max(op2, 1 + func(i+1, j+1, k-1));
	}
	return dp[i][j][k] = max(op1, op2);
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    mem(dp, -1);
    ll k;
	cin>>n>>m>>k;
	F(a, n);
	F(b, m);
	cout<<func(0, 0, k);
}
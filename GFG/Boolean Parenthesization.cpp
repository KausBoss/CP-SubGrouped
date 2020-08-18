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
const int mod = 1003;
ll dp[101][101][2];
string s;
ll n;

ll func(ll i, ll j, bool ret){
	//base case
	if(j < i){
		bool ret1 = (s[i-1]=='T');
		return dp[i][j][ret] = (ret1 == ret);
	}
	if(i == j){
		bool op1 = (s[i-1] == 'T');
		bool op2 = (s[i+1] == 'T');
		if(s[i] == '|'){return ((op1|op2) == ret);}
		if(s[i] == '&'){return ((op1&op2) == ret);}
		return dp[i][j][ret] = ((op1^op2) == ret);
	}
	//recursive case
	if(dp[i][j][ret] != -1){ return dp[i][j][ret];}
	ll ans = 0;
	if(ret == 1){
		for(int k=i; k<=j; k+=2){
			if(k == '|'){
				ans += (func(i, k-2, 1) * func(k+2, j, 1))%mod;
				ans %= mod;
				ans += (func(i, k-2, 1) * func(k+2, j, 0))%mod;
				ans %= mod;
				ans += (func(i, k-2, 0) * func(k+2, j, 1))%mod;
				ans %= mod;
			} 
			else if(k == '&'){
				ans += (func(i, k-2, 1) * func(k+2, j, 1))%mod;
				ans %= mod;
			}
			else{
				ans += (func(i, k-2, 1) * func(k+2, j, 0))%mod;
				ans %= mod;
				ans += (func(i, k-2, 0) * func(k+2, j, 1))%mod;
				ans %= mod;
			}
		}
		return dp[i][j][ret] = (ans%mod);
	}
	for(int k=i; k<=j; k+=2){
		if(k == '|'){
			ans += (func(i, k-2, 0) * func(k+2, j, 0))%mod;
			ans %= mod;
		} 
		else if(k == '&'){
			ans += (func(i, k-2, 0) * func(k+2, j, 0))%mod;
			ans %= mod;
			ans += (func(i, k-2, 1) * func(k+2, j, 0))%mod;
			ans %= mod;
			ans += (func(i, k-2, 0) * func(k+2, j, 1))%mod;
			ans %= mod;
		}
		else{
			ans += (func(i, k-2, 1) * func(k+2, j, 1))%mod;
			ans %= mod;
			ans += (func(i, k-2, 1) * func(k+2, j, 1))%mod;
			ans %= mod;
		}
	}
	return dp[i][j][ret] = (ans%mod);
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		mem(dp, -1);
		cin>>n;
		cin>>s;
		cout<<func(1, n-2, 1)<<endl;
	}
}
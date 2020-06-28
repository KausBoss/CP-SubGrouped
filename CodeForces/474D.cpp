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
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e5 + 2;
const int mod = 1e9+7;
ll dp[nax], k;

ll func(ll i){
	//base case
	if(i < 0){
		return 0;
	}
	if(i == 0){
		return 1;
	}
	//recursive case
	if(dp[i] != -1){ return dp[i];}

	ll op1 = func(i - 1);
	ll op2 = func(i - k);

	return dp[i] = (func(i-1) + func(i-k))%mod;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll t;
	memset(dp, -1, sizeof(dp));
	cin>>t>>k;
	func(1e5);
	dp[0] = 0;
	for(ll i=1; i<nax; i++){
		dp[i] += dp[i-1];
		dp[i] %= mod;
	}
	while(t--){
		ll a, b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1] + mod)%mod<<endl;
	}
}
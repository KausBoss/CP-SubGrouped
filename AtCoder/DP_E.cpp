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
const int nax = 1e5 + 1;
const ll mod = 1e11+7;



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n, capacity;
	cin>>n>>capacity;
	ll *weight = new ll[n+1];
	ll *cost = new ll[n+1];
	ll max_cost = 0;
	for(ll i=1; i<=n; i++){
		cin>>weight[i]>>cost[i];
		max_cost += cost[i];
	}
	ll dp[101][max_cost + 2];
	memset(dp, mod, sizeof(dp));
	for(ll i=0; i<=n; i++){
		dp[i][0] = 0;
	}

	for(ll i=1; i<=n; i++){
		for(ll j=0; j<=max_cost; j++){
			ll op1 = dp[i-1][j];
			ll op2 = (cost[i] <= j) ? (weight[i] + dp[i-1][j - cost[i]]) : mod;
			dp[i][j] = min(op1, op2);
		}
	}
	ll ans = 0;
	for(ll i=0; i<=max_cost; i++){
		if(dp[n][i] <= capacity){
			ans = i;
		}
	}

	cout<<ans;
}
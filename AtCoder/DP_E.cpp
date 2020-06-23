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
const int nax = 1e5 + 5;
const int mod = 1e9+7;
ll n, w;
ll *weight, *cost;
ll dp[101][nax];

ll func(ll i, ll w_curr){
	//base case
	if(w == 0){
		return 0;
	}
	if(i == n){
		return 0;
	}
	//recursive case
	if(dp[i][w_curr] != -1){ return dp[i][w_curr];}

	ll op1 = func(i + 1, w_curr);
	ll op2 = weight[i] > w_curr ? 0 : cost[i] + func(i + 1, w_curr - weight[i]);

	return dp[i][w_curr] = max(op1, op2);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n>>w;
    memset(dp, -1, sizeof(dp));
	weight = new ll[n];
	cost = new ll[n];
	for(int i=0; i<n; i++){
		cin>>weight[i];
		cin>>cost[i];
	}
	cout<<func(0, w);
}
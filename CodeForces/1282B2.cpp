/*
first we sort the prices of the items
if(i < k){
	dp[i] = cost[i] + dp[i-1];
}
else if(i == k){
	dp[i] = cost[i];
}
else{
	dp[i] = cost[i] + dp[i-k];
}

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

ll func(){
	ll n, p, k, ans = 0;
	cin>>n>>p>>k;
	ll *cost = new ll[n+1];
	F1(cost, n);
	sort(cost + 1, cost + n + 1);
	cost[0] = 0;
	ll *dp = new ll[n+1];
	dp[0] = 0;
	for(ll i=1; i<=n; i++){
		if(i < k){
			dp[i] = cost[i] + dp[i-1];
		}
		else if(i == k){
			dp[i] = cost[i];
		}
		else{
			dp[i] = cost[i] + dp[i-k];
		}

		if(dp[i] <= p){ans = i;}
	}
	return ans;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		cout<<func()<<endl;
	}
}
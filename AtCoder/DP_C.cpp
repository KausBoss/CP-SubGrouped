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
const int nax = 1e7;
const int mod = 1e9+7;



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n, ans=0;cin>>n;
	ll cost[n][3], dp[n][3];
	for(ll i=0; i<n; i++){
		cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
		if(i == 0){
			dp[0][0] = cost[0][0];
			dp[0][1] = cost[0][1];
			dp[0][2] = cost[0][2];
			ans = max(dp[0][0], max(dp[0][1], dp[0][2]));
		}
	}

	for(ll i=1; i<n; i++){
		dp[i][0] = cost[i][0] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = cost[i][1] + max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = cost[i][2] + max(dp[i-1][0], dp[i-1][1]);
		if(i == n-1){
			ans = max(dp[i][0], max(dp[i][1], dp[i][2]));
		}
	}
	cout<<ans;
}
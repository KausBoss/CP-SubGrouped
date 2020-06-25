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
const ll nax = 1e16;
const int mod = 1e9+7;



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n; cin>>n;
	ll *c = new ll[n];
	F(c, n);
	string s[n][2];
	for(ll i=0; i<n; i++){
		cin>>s[i][1];
		s[i][0] = s[i][1];
		reverse(s[i][1].begin(), s[i][1].end());
	}
	vector<vector<ll>> dp(n, vector<ll>(2, nax));
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for(ll i=1; i<n; i++){
		if(s[i][0] >= s[i-1][0]){
			dp[i][0] = dp[i-1][0];
		}
		
		if(s[i][0] >= s[i-1][1] && dp[i][0] > dp[i-1][1]){
			dp[i][0] = dp[i-1][1];	
		}

		if(s[i][1] >= s[i-1][0]){
			dp[i][1] = c[i] + dp[i-1][0];
		}
		
		if(s[i][1] >= s[i-1][1] && dp[i][1] > c[i] + dp[i-1][1]){
			dp[i][1] = c[i] + dp[i-1][1];
		}
	}
	ll ans = min(dp[n-1][0], dp[n-1][1]);
	if(ans >= nax){
		cout<<-1;
		return 0;
	}
	cout<<ans;
}
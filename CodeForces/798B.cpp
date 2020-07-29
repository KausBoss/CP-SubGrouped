/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll            long long int
#define vi  		  vector<int>
#define pb            push_back
#define fi            first
#define si            second
#define pii 	 	  pair<int,int>
#define vii 		  vector<pair<int,int>>
#define F(a,n)        for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n)        for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n)       for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)       for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)      memset(a, b, sizeof a)
#define matrix(x)  	  vector<vector<x>>
#define NF(a,n,m)     for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
string s[512];
ll dp[512][512];

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	for(ll i=1; i<=n; i++){
		cin>>s[i];
	}
	ll k=s[1].length();
	for(ll i=1; i<=n; i++){
		for(ll j=0; j<k; j++){
			dp[i][j] = 1e9;
		}
	}

	for(ll i=1; i<=n; i++){
		s[i] += s[i];
	}
	for(ll i=0; i<k; i++){
		dp[1][i]=i;
	}

	for(ll i=2; i<=n; i++){
		for(ll j=0; j<k; j++){
			for(ll prev=0; prev<k; prev++){
				if(s[i].substr(j,k) == s[i-1].substr(prev,k)){
					dp[i][j] = min(dp[i][j], dp[i-1][prev] + j);
				}
			}
		}
	}

	ll ans=1e9;
	for(int i=0; i<k; i++){
		ans = min(ans, dp[n][i]);
	}
	if(ans == 1e9){
		puts("-1");
	}
	else{
		cout<<ans<<"\n";
	}
	// PNF(dp, n+1, k);
	return 0;
}
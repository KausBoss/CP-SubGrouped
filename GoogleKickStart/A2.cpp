/*

*/
#include <bits/stdc++.h>

using namespace std;

#define int           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;

int func(){
	int n, k, p;
	cin>>n>>k>>p;
	vector<vector<int>> plates(n, vector<int>(k)), sum(n, vector<int>(k+1));
	NF(plates, n, k);
	for(int i=0; i<n; i++){sum[i][1] = plates[i][0];}
	for(int i=0; i<n; i++){
		for(int j=1; j<k; j++){
			sum[i][j+1] = plates[i][j] + sum[i][j];
		}
	}
	vector<vector<int>> dp(n, vector<int>(p+1, 0));
	for(int i=1; i<=min(k,p); i++){dp[0][i] = sum[0][i];}

	for(int i=1; i<n; i++){
		for(int j=0; j<=p; j++){
			for(int l=0; l<=min(j, k); l++){
				dp[i][j] = max(dp[i][j], sum[i][l] + dp[i-1][j-l]);
			}
		}
	}
	return dp[n-1][p];
}

int32_t main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
	freopen("../out.txt","w",stdout);
	#endif
	int t=1;cin>>t;
	for(int i=1; i<=t; i++){
		cout<<"Case #"<<i<<": "<<func()<<"\n";
	}
}
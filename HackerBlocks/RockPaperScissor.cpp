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
const int mod = 1e9+7;
double dp[101][101][101];

double func(ll R, ll S, ll P){
	//base case
	if(R==0 || S==0){
		return 0.0;
	}
	if(P == 0){
		return 1.0;
	}
	//recursive case
	if(dp[R][S][P] > -1){ return dp[R][S][P];}
	ll total = R*S + R*P + S*P;
	double ans = 0;
	ans += (R*S)*func(R, S-1, P);
	ans += (R*P)*func(R-1, S, P);
	ans += (S*P)*func(R, S, P-1);
	ans /= total;

	return dp[R][S][P] = ans; 
}


int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;cin>>t;
	while(t--){
		ll R, S, P;
		mem(dp, -1);
		cin>>R>>S>>P;
		cout<<fixed<<setprecision(9)<<func(R, S, P)<<" "
				   					<<func(S, P, R)<<" "
				   					<<func(P, R, S)<<endl;
	}
}
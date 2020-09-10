/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
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
ll n, a[100], dp[100][100], prefix[100];

ll sum(int s, int e){
	if(s==0){return prefix[e]%100;}
	return (prefix[e] - prefix[s-1])%100;
}

ll func(int i, int j){
	//base case
	if(i == j){return 0;}
	//recursive case
	if(dp[i][j]!=-1){return dp[i][j];}
	ll ans = INT_MAX;
	for(int k=i; k<j; k++){
		ans = min(ans, func(i, k) + func(k+1, j) + sum(i, k)*sum(	k+1, j));
	}
	return dp[i][j] = ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    cin>>n;
	while(n){
		F(a, n);
		mem(dp, -1);
		prefix[0] = a[0];
		for(int i=1; i<n; i++){
			prefix[i] = (prefix[i-1] + a[i]);
		}
		cout<<func(0, n-1)<<"\n";
		n = 0;
		cin>>n;
	}
}
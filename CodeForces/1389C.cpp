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
const int nax = 2e5 + 5;
const int mod = 1e9+7;
ll dp[nax][11][11];
string s;
ll n;
ll func(int i, int c1, int c2, int len){
	//base case
	if(i == n){
		return ((len&1) && c1!=c2);
	}
	//recursive case
	if(dp[i][c1][c2]!=-1){return dp[i][c1][c2];}
	if(c1 == 10){
		return dp[i][c1][c2] = min(func(i+1, c2, (s[i]-'0'), len+1), 1+func(i+1, c1, c2, len));
	}
	if((s[i]-'0') == c1){
		return dp[i][c1][c2] = func(i+1, c2, c1, len+1);
	}
	return dp[i][c1][c2] = 1 + func(i+1, c1, c2, len);
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
		cin>>s;
		n=s.length();
		mem(dp, -1);
		cout<<func(0, 10, 10, 0)<<endl;
	}
}
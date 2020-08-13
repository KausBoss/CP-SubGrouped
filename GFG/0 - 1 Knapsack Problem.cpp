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
pair<int, int> item[1001];
int n, W;
int dp[1001][1001];

int knapsack(int i, int w){
	//base case
	if(i == n || w == 0){
		return 0;
	}
	//recursive case
	if(dp[i][w] != -1){return dp[i][w];}

	if(item[i].fi <= w){
		int op1 = knapsack(i+1, (w-item[i].fi))+item[i].si;
		int op2 = knapsack(i+1, w);
		return dp[i][w] = max(op1, op2);
	}
	return dp[i][w] = knapsack(i+1, w);
}


void func(){
	cin>>n>>W;
	for(int i=0; i<n; i++){
		cin>>item[i].si;
	}
	for(int i=0; i<n; i++){
		cin>>item[i].fi;
	}
	sort(item, item+n);
	mem(dp, -1);
	cout<<knapsack(0, W)<<endl;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}
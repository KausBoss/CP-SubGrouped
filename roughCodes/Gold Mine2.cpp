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
int n, m, mat[10][10];





int helper(int i, int j, vector<vector<bool>> &visited){
	//base case
	if(i <0 || j<0 || i==n || j==m || visited[i][j] || mat[i][j]==0){return 0;}
	//recursive case
	int val = mat[i][j];
	visited[i][j] = 1;
	val += helper(i+1, j, visited);
	val += helper(i, j+1, visited);
	val += helper(i-1, j, visited);
	val += helper(i, j-1, visited);
	return val;
}

int func(int i, int j){
	//base case
	if(i == n){return 0;}
	if(j == n){return func(i+1, 0);}
	//recursiev case
	vector<vector<bool>> visited(n, vector<bool>(m, 0));
	return max(helper(i, j, visited), func(i, j+1));
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	cin>>n>>m;
	NF(mat, n, m);
	cout<<func(0 ,0);
}
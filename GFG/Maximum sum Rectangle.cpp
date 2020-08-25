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


void func(){
	int mat[100][100];
	int n, m;
	cin>>n>>m;
	NF(mat, n, m);
	int topRow, BotCol, LeftCol, RightCol;
	int maxSum=0;
	for(int T=0; T<n; T++){
		vector<int> v(m, 0);
		for(int B=T; B<n; B++){
			//adding new row to v
			for(int i=0; i<m; i++){v[i] += mat[B][i];}
			//applying kadane's algorithm
			int cs=0, st=-1;
			for(int i=0; i<m; i++){
				cs += v[i];
				if(st == -1){st=i;}
				if(cs > maxSum){
					topRow = T;
					BotCol = B;
					RightCol = st;
					LeftCol = i;
					maxSum = cs;
				}
				if(cs < 0){
					cs = 0;
					st = -1;
				}
			}
		}
	}
	cout<<maxSum<<endl;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}
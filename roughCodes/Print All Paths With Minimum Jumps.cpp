/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
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

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	ll n, a[100], dp[100];
	cin>>n;
	F(a, n);
	for(int i=1; i<n; i++){dp[i]=INT_MAX;}
	dp[0] = 0;
	for(int i=0; i<n; i++){
		for(int j=i+a[i]; j>i; j--){
			dp[j] = min(dp[j], 1 + dp[i]);
		}
	}
	cout<<dp[n-1]<<endl;
	queue<pair<int, vector<int>>> q;
	q.push({n-1, {}});
	while(!q.empty()){
		auto node = q.front();
		q.pop();
		node.si.pb(node.fi);
		if(node.fi == 0){
			reverse(node.si.begin(), node.si.end());
			for(int i=0; i<node.si.size(); i++){
				cout<<node.si[i];
				if(i==node .si.size()-1){cout<<" .\n";}
				else{cout<<" -> ";}
			}
		}
		else{
			for(int i=0; i<node.fi; i++){
				if(dp[i] == dp[node.fi]-1 && i+a[i]>=node.fi){
					q.push({i, node.si});
				}
			}
		}
	}
}
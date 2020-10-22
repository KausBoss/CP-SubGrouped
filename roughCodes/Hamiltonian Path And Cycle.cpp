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
vector<int> g[20];
int n, m, src;
vector<bool> visited(20, 0);
vector<vector<int>> cycle, hamil;

void dfs(int node, vector<int> path){
	//base case
	visited[node] = 1;
	path.pb(node);
	if(path.size() == n){
		if(std::find(g[node].begin(), g[node].end(), src) != g[node].end()){
			cycle.pb(path);
		}
		else{
			hamil.pb(path);
		}
		path.pop_back();
		visited[node] = 0;
		return;
	}
	//recursive case
	for(auto child:g[node]){
		if(visited[child] == 0){
			dfs(child, path);
		}
	}
	path.pop_back();
	visited[node] = 0;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x, y, w;
		cin>>x>>y>>w;
		g[x].pb(y);
		g[y].pb(x);
	}
	cin>>src;
	dfs(src,{});
	for(auto x: hamil){
		for(auto y:x){
			cout<<y;
		}
		cout<<".\n";
	}
	for(auto x:cycle){
		for(auto y:x){
			cout<<y;
		}
		cout<<"*\n";
	}
}
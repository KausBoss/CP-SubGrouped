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
vector<list<ll>> g(2000);
vector<bool> visited(2000, 0);


void dfs(ll node, stack<ll> &s){
	visited[node] = 1;
	for(auto child:g[node]){
		if(!visited[child]){
			dfs(child, s);	
		}
	}
	s.push(node);
}


ll dfs2(ll node){
	visited[node] = 1;
	ll val = 0;
	for(auto child:g[node]){
		if(!visited[child]){
			val = max(val , dfs2(child));
		}
	}
	return 1 + val;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	ll n, ans=1;
	cin>>n;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		if(x != -1){
			x--;
			g[x].pb(i);
		}
	}
	stack<ll> s;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			dfs(i, s);
		}
	}
	visited = vector<bool>(n, 0);

	while(!s.empty()){
		if(!visited[s.top()]){
			ll topper = s.top();
			ans = max(ans, dfs2(topper));
		}
		s.pop();
	}
	cout<<ans;
}
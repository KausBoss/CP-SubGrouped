/*

*/
#include <bits/stdc++.h>

using namespace std;

#define int          long long int
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
const int nax = 2e5 + 10;
const int mod = 1e9+7;
int visited[nax][2];
int val[nax], parent[nax];

void dfs(int node, bool parity, vector<int> g[], int src, int par){
	if(node != src && parity==0){
		val[src] += val[node];
		val[node] = 0;
	}

	if(visited[node][parity] == 0){
		for(auto  child: g[node]){
			if(child != par){
				dfs(child, parity^1, g, src, node);
			}
		}
		visited[node][parity] = 1;
	}
}

void findParent(int v, vector<int> g[], int par){
	parent[v] = par;
	for(auto child:g[v]){
		if(child != par){
			findParent(child, g, v);
		}
	}
	return;
}

int32_t main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		int n, i, j, x, u, v, q;
		cin>>n>>q;

		for(i=0; i<nax; i++){
			visited[i][0] = 0;
			visited[i][1] = 0;
		}

		for(i=0; i<n; i++){
			cin>>val[i];
		}

		vector<int> g[n];
		for(int i=0; i<n-1; i++){
			cin>>u>>v;
			u--;v--;
			g[u].pb(v);
			g[v].pb(u);
		}

		findParent(0, g, -1);
		while(q--){
			cin>>x;x--;
			if(visited[x][0] == 1){
				continue;
			}
			dfs(x, 0, g, x, parent[x]);
			visited[x][0]=1;
		}
		P(val, n);
	}
}
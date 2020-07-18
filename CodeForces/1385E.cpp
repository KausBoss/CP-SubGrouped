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
const int nax = 1e7;
const int mod = 1e9+7;


vi topoSortBFS(matrix(int) adj){
	int n =adj.size();
	vi inDeg(n, 0);
	queue<int> q;
	vi order;
	for(int i=0; i<n; i++){
		for(auto it:adj[i]){
			inDeg[it]++;
		}
	}
	for(int i=0; i<n; i++){
		if(!inDeg[i]){
			q.push(i);
		}
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();
		order.pb(u);
		for(auto v:adj[u]){
			inDeg[v]--;
			if(inDeg[v] == 0){
				q.push(v);
			}
		}
	}
	return order;
}

void solve(){
	int n, m;
	cin>>n>>m;
	matrix(int) adj(n);
	vii edges;
	for(int i=0; i<m; i++){
		int t, x, y;
		cin>>t>>x>>y;
		x--;y--;
		edges.pb({x, y});
		if(t == 1){
			adj[x].pb(y);
		}
	}
	vi order=topoSortBFS(adj);
	if(order.size() < n){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	vi idx(n, -1);
	for(int i=0; i<n; i++){
		idx[order[i]] = i;
	}
	for(auto e:edges){
		if(idx[e.first] > idx[e.second]){
			swap(e.first, e.second);
		}
		cout<<e.first+1<<" "<<e.second+1<<endl;
	}
}

int32_t main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
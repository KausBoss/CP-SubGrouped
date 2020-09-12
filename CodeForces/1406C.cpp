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
ll n, cut;
vector<ll> maxSub;
vector<list<ll>> g;
vector<bool> visited;

ll dfs(int node){
	visited[node] = 1;
	ll total=0;
	for(auto child:g[node]){
		if(visited[child] == 0){
			ll val = dfs(child);
			maxSub[node] = max(maxSub[node], val);
			total += val;
		}
	}
	maxSub[node] = max(maxSub[node], n-total-1);
	return total + 1;
}

void dfs_2(int node, int emeny){
	// cout<<node<<" "<<emeny<<endl;
	visited[node] = 1;
	if(node == emeny){return;}
	if(g[node].size() == 1){
		cut = node;
		return;
	}
	for(auto child:g[node]){
		if(visited[child]==0){
			dfs_2(child, emeny);
		}
	}
	return;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		cin>>n;
		g = vector<list<ll>>(n);
		maxSub = vector<ll>(n, 0);
		visited = vector<bool>(n, 0);
		for(int i=0; i<n-1; i++){
			ll x, y;
			cin>>x>>y;
			x--;y--;
			g[x].pb(y);
			g[y].pb(x);

		}
		dfs(0);
		vector<pair<ll,ll>> v;
		for(int i=0; i<n; i++){
			v.pb({maxSub[i], i});
		}
		sort(v.begin(), v.end());
		if(v[0].fi < v[1].fi){
			cout<<1<<" "<<g[0].back()+1<<endl;
			cout<<1<<" "<<g[0].back()+1<<endl;
		}
		else{
			visited = vector<bool>(n, 0);
			dfs_2(v[1].si, v[0].si);
			cout<<cut+1<<" "<<g[cut].back()+1<<endl;
			cout<<cut+1<<" "<<v[0].si+1<<endl;
		}
	}
}
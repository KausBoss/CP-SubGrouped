/*
*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 2e5 + 2;
const int mod = 1e9+7;
vector<list<ll>> g(nax);
bool visited[nax]={0};
ll freq[nax]={0};
ll n, m, r;

void dfs(ll node){
	visited[node] = 1;
	bool leaf = 1;
	for(auto child:g[node]){
		if(!visited[child]){
			leaf = 0;
			dfs(child);
		}
	}
	if(leaf){freq[node]++;}
	visited[node] = 0;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>m>>r;
	// memset(freq, 0, sizeof(freq));
	// memset(visited, 0, sizeof(visited));
	for(ll i=0; i<m; i++){
		ll u, v;
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
	}
	r--;
	dfs(r);

	ll ff=-1;
	for(int i=0; i<n; i++){
		ff = max(ff, freq[i]);
	}
	for(int i=0; i<n; i++){
		if(ff == freq[i]){
			cout<<i+1<<" ";
		}
	}
}
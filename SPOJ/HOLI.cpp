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
ll n, ans=0;
vector<list<pair<ll,ll>>> g;
vector<bool> visited;

ll dfs(ll node){
	visited[node] = 1;
	ll cnt = 1;
	for(auto child:g[node]){
		if(!visited[child.fi]){
			ll val = dfs(child.fi);
			ans += 2 * child.si * min(val, (n - val));
			cnt += val;
		}
	}
	return cnt ;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	for(int ii=1; ii<=t; ii++){
		cin>>n;
		g = vector<list<pair<ll,ll>>>(n);
		visited = vector<bool>(n, 0);
		ans = 0;
		for(int i=0; i<n-1; i++){
			ll x, y, w;
			cin>>x>>y>>w;
			x--;y--;
			g[x].pb({y, w});
			g[y].pb({x, w});
		}
		dfs(0);
		cout<<"Case #"<<ii<<": "<<ans<<endl;
	}
}
/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
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
const int nax = 200000;
const int mod = 1e9+7;
vector<ll> g[nax];
vector<bool> visited(nax, 0);
vector<ll> A(nax);
vector<bool> gogo(nax, 0);
vector<bool> visited2(nax, 0);
vector<bool> init(nax);


ll helper_dfs(ll node, bool lelo, ll par){
	visited2[node] = 1;
	ll neeche=0;
	for(auto child:g[node]){
		if(!visited2[child] && child != par){
			neeche += helper_dfs(child, !lelo, node);
		}
	}
	if(lelo){neeche += A[node];A[node]=0;}
	visited2[node] = 0;
	return neeche;
}

void dfs(ll node){
	visited[node] = 1;
	if((A[node]>0 || init[node]) && gogo[node]){
		for(auto child:g[node]){
			if(visited[child] == 0){
				A[node] += helper_dfs(child,0, node);
			}
		}
	}
	for(auto child:g[node]){
		if(visited[child] == 0){
			dfs(child);
		}
	}
}

void func(){
	ll n, q;
	cin>>n>>q;
	F(A, n);
	for(int i=0; i<n; i++){
		if(A[i] == 0){init[i] = 1;}
	}
	for(int i=0; i<n-1; i++){
		ll x, y;
		cin>>x>>y;
		x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	while(q--){
		ll node;cin>>node;
		node--;
		gogo[node] = 1;
	}
	dfs(0);
	P(A, n);
	for(int i=0; i<n; i++){
		g[i].clear();
		visited[i]=0;
		visited2[i]=0;
		gogo[i] = 0;
		init[i] = 0;
	}
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
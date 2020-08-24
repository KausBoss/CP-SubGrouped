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
vector<vector<ll>> adj;
string s;
ll uno=0, dos=0;

void dfs(ll node, bool last, vector<bool> visit){
	if(last){dos++;}
	else{uno++;}
	visit[node] = 1;
	for(auto child: adj[node]){
		if(!visit[child]){
			dfs(child, !last, visit);
		}
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
		ll n;
		cin>>n;
		adj = vector<vector<ll>>(n);
		for(int i=0; i<n-1; i++){
			ll x, y;
			cin>>x>>y;
			x--;y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		cin>>s;
		ll c1=0, c0=0;
		for(int i=0; i<n; i++){
			id(s[i] == '1'){c1++;}
			else{c0++;}
		}
		if(c1 < c0){swap(c1, c0);}
		vector<bool> visit(n, 0);
		dfs(0, 1, visit);
		if(uno < dos){swap(uno, dos);}
		if(uno != c1 || dos!= c0){
			cout<<-1<<endl;
			continue;
		}
	}
}
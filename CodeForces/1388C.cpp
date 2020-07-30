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
const int nax = 1e5 + 1;
const int mod = 1e9+7;
ll n, m, p[nax], h[nax], passer[nax], GG[nax];
vector<vector<ll>> g;
vector<bool> visited;
bool correct;

ll dfsPass(ll node){
	visited[node]=1;
	passer[node] = p[node];
	for(auto child:g[node]){
		if(!visited[child]){
			passer[node] += dfsPass(child);
		}
	}
	return passer[node];
}

ll dfsChecker(ll node){
	visited[node] = 1;
	if(((passer[node]+h[node])%2 != 0)){
		correct =0;
		return 0;
	}
	GG[node] = (passer[node]+h[node])/2;
	if(GG[node]<0 || GG[node]>passer[node]){
		correct = 0;
		return 0;
	}
	ll happyChild=0;
	for(auto child:g[node]){
		if(!visited[child]){
			happyChild += dfsChecker(child);
		}
	}
	if(happyChild > GG[node]){
		correct = 0;
		return 0;
	}
	return GG[node];
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		correct=true;
		cin>>n>>m;
		g = vector<vector<ll>>(n);
		F(p, n);
		F(h, n);
		for(int i=0; i<n-1; i++){
			ll a, b;
			cin>>a>>b;
			a--;b--;
			g[a].pb(b);
			g[b].pb(a);
		}
		visited = vector<bool>(n, 0);
		dfsPass(0);
		visited = vector<bool>(n, 0);
		dfsChecker(0);
		if(correct){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
		// cout<<"passer\n";
		// P(passer, n)
		// cout<<"\n\nGG\n";
		// P(GG, n);
		// cout<<correct;
		g.clear();
	}
}
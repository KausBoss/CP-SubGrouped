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
const int nax = 1e7;
const int mod = 1e9+7;

class dsu{
	vector<ll> parent, rank;
	ll total_component;
public:
	dsu(int n){
		parent.resize(n);
		rank.resize(n);
		for(int i=0; i<n; i++){
			parent[i] = i;
			rank[i] = 0;
		}
		total_component = n;
	}

	ll get(ll a){
		if(parent[a] == a){
			return a;
		}
		
		return parent[a] = get(parent[a]);
	}

	void union_set(ll a, ll b){
		a = get(a);
		b = get(b);
		if(a != b){
			if(rank[a] < rank[b]){
				swap(a, b);
			}
			parent[b] = a;
			if(rank[a] == rank[b]){
				rank[a]++;
			}
			total_component--;
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		int n, m, u, v;
		bool cycle = 0;
		cin>>n>>m;
		dsu g(n);
		vector<pair<int, int>> edge(m);
		for(int i=0; i<m; i++){
			cin>>u>>v;
			if(g.get(u) == g.get(v)){
				cycle = 1;
			}
			else{
				g.union_set(u, v);
			}
		}
		cout<<cycle<<endl;
	}
}
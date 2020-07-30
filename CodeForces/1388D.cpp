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
const int nax = 2e5 + 5;
const int mod = 1e9+7;
ll a[nax], b[nax];
vector<vector<ll>> m;
int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	F(a, n);
	F(b, n);
	for(int i=0; i<n; i++){
		if(b[i]!=-1){
			b[i]--;
		}
	}
	m = vector<vector<ll>>(n);
	vector<ll> indegree(n, 0);
	for(ll i=0; i<n; i++){
		if(b[i]!=-1){
			m[i].pb(b[i]);
			indegree[b[i]]++;
		}
	}

	queue<ll> q;
	for(ll i=0; i<n; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	vector<ll> topo;
	while(!q.empty()){
		ll node = q.front();
		q.pop();
		topo.pb(node);
		for(auto child:m[node]){
			indegree[child]--;
			if(indegree[child] == 0){
				q.push(child);
			}
		}
	}
	ll ans=0;
	vector<ll> final, aux;
	for(auto x:topo){
		if(a[x] >= 0){
			ans += a[x];
			final.pb(x);
			if(b[x]!=-1){a[b[x]] += a[x];}
		}
		else{
			aux.pb(x);
		}
	}
	reverse(aux.begin(), aux.end());
	for(auto x:aux){
		ans += a[x];
		final.pb(x);
		if(b[x]!=-1){a[b[x]] += a[x];}
	}
	cout<<ans<<endl;
	for(auto x: final){
		cout<<x+1<<" ";
	}
}
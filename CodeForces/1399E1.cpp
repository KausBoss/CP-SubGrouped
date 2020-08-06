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
const int nax = 1e5 + 5;
const int mod = 1e9+7;
vector<pair<ll, ll>> g[nax];
vector<ll> depLeaf(nax);
vector<ll> edgeW(nax);
ll n;

ll dfs(ll node, ll parent){
	//base case
	if(g[node].size() == 1 && g[node][0].fi == parent){
		return 1;
	}
	//recursive case
	int ret=0;
	for(auto c:g[node]){
		if(c.fi == parent){continue;}
		depLeaf[c.fi] = dfs(c.fi, node);
		edgeW[c.fi] = c.si;
		ret += depLeaf[c.fi];
	}
	return ret;
}

ll diff(ll i){
	return (edgeW[i]*depLeaf[i] - (edgeW[i]/2)*depLeaf[i]);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;cin>>t;
	while(t--){
		ll S, sum=0;
		cin>>n>>S;
		for(int i=0; i<n-1; i++){
			ll x, y, w;
			cin>>x>>y>>w;
			x--;y--;
			g[x].pb({y, w});
			g[y].pb({x, w});
		}
		dfs(0, -1);
		// P(edgeW, n);
		// P(depLeaf, n);
		priority_queue<pair<ll, ll>> p;
		for(int i=1; i<n; i++){
			ll val = (edgeW[i] - (edgeW[i]/2))*depLeaf[i];
			p.push({val, i});
			sum += edgeW[i]*depLeaf[i];
		}
		ll ans=0;
		while(sum > S){
			ans++;
			auto i = p.top().si;
			p.pop();
			sum -= diff(i);
			edgeW[i] /= 2;
			p.push({diff(i), i});
		}
		cout<<ans<<endl;
		for(int i=0; i<n; i++){g[i].clear();}
	}
}
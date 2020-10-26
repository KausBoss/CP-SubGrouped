/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e5;
const int mod = 1e9+7;
ll n, m, k, special[nax], ans[nax];
bool visited[nax];
vector<ll> g[nax];



int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=0; i<m; i++){
			ll x, y;
			cin>>x>>y;
			x--;y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		for(int i=0; i<k; i++){
			cin>>special[i];
			special[i]--;
		}
		for(int i=0; i<n; i++){
			ans[i] = -1;
			visited[i] = 0;
		}
		queue<pair<ll, ll>> q;
		for(int i=0; i<k; i++){
			ans[special[i]]=0;
			q.push({special[i], 0});
			visited[special[i]] = 1;
		}
		while(!q.empty()){
			pair<ll,ll> node = q.front();
			q.pop();
			for(auto child: g[node.fi] ){
				if(visited[child]==0){
					visited[child] = 1;
					ans[child] =node.si + 1;
					q.push({child, node.si + 1});
				}
			}

		}
		ll qt;cin>>qt;
		while(qt--){
			ll node;
			cin>>node;
			node--;
			cout<<ans[node]<<"\n";
		}
		for(int i=0; i<n; i++){g[i].clear();}
	}
}
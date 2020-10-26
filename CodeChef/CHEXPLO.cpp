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
vector<ll> g[nax];
ll n;
bool visited[nax];

void func(){
	
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
		for(int i=0; i<n-1; i++){
			ll x, y;
			cin>>x>>y;
			x--;y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		ll max_dis=0, last_node;
		for(int i=0; i<n; i++){
			visited[i] = 0;
		}
		queue<pair<ll, ll>> q;
		q.push({0, 0});
		visited[0] = 1;
		while(!q.empty()){
			ll node = q.front().fi;
			ll dist = q.front().si;
			q.pop();
			max_dis = max(max_dis, dist);
			last_node = node;
			for(auto child:g[node]){
				if(!visited[child]){
					q.push({child, dist+1});
					visited[child] = 1;
				}
			}
		}
		for(int i=0; i<n; i++){
			visited[i] = 0;
		}
		q.push({last_node, 0});
		visited[last_node] = 1;

		while(!q.empty()){
			ll node = q.front().fi;
			ll dist = q.front().si;
			q.pop();
			max_dis = max(max_dis, dist);
			last_node = node;
			for(auto child:g[node]){
				if(!visited[child]){
					q.push({child, dist+1});
					visited[child] = 1;
				}
			}
		}
		cout<<(max_dis+1)/2<<"\n";
		for(int i=0; i<n; i++){g[i].clear();}
	}
}
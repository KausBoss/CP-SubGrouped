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
vector<vector<pair<ll,ll>>> g;
ll n, m;

ll FindMin(vector<bool> visited, vector<ll> weight){
	ll minVertex = -1;
	for(ll i=0; i<n; i++){
		if(!visited[i] && (minVertex==-1 || weight[minVertex] > weight[i])){
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(){
	vector<bool> visited(n, 0);
	vector<ll> weight(n, INT_MAX);//current weight of vertices
	map<ll, ll> parent;// to retrieve the spanning tree

	//Marking the node ) as src
	//NOTE: we can choose any node
	parent[0] = -1;
	weight[0] = 0;

	for(int i=0; i<n-1; i++){//MST has n-1 edges
		ll minNode = FindMin(visited, weight); //to find the unvisited node with min weight
		
		// marking minNode as visited
		visited[minNode] = 1;

		//iterating over its children
		for(auto child:g[minNode]){
			if(!visited[child.fi] && weight[child.fi] > child.si){
				weight[child.fi] = child.si;
				parent[child.fi] = minNode;
			}
		}
	}

	//Printing the MST
	for(ll i=1; i<n; i++){
		cout<<i+1<<" is connect to "<<parent[i]+1<<" with cost "<<weight[i]<<endl;
	}
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n>>m;

    g.resize(n);
    for(int i=0; i<m; i++){
    	ll u, v, w;
    	cin>>u>>v>>w;
    	u--;v--;
    	g[u].pb({v, w});
    	g[v].pb({u, w});
    }

    prims();
}
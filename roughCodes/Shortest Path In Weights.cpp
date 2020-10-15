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
const int nax = 1e7;
const int mod = 1e9+7;

class ptr{
public:
	int node, cost;
	string path;
	ptr(int node, int cost, string path){
		this->node = node;
		this->cost = cost;
		this->path = path;
	}
};

struct comp{
	bool operator()(ptr a, ptr b){
		if(a.cost == b.cost){
			return a.path.length() < b.path.length();
		}
		return a.cost > b.cost;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int n, m, src;
	vector<pair<int, int>> g[10];
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x, y, w;
		cin>>x>>y>>w;
		g[x].pb({y, w});
		g[y].pb({x, w});
	}
	cin>>src;
	vector<bool> visited(10, 0);
	priority_queue<ptr, vector<ptr>, comp> q;
	ptr a(src, 0, "");
	q.push(a);
	while(1){
		while(!q.empty() && visited[q.top().node]==1){
			q.pop();
		}
		if(q.empty()){break;}
		ptr node = q.top();
		q.pop();
		node.path += to_string(node.node);
		visited[node.node] = 1;
		cout<<node.node<<" via "<<node.path<<" @ "<<node.cost<<endl;
		for(auto child:g[node.node]){
			if(visited[child.fi]==0){
				ptr x(child.fi, node.cost + child.si, node.path);
				q.push(x);
			}
		}
	}

}
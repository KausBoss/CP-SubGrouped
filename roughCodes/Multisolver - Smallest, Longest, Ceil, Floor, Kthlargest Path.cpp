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
int n, m, src, dest;
int criteria, k;
vector<pair<int, string>> paths;
vector<vector<pair<int, int>>> g;

void dfs(int node, string path, int cost, vector<bool> & visited){
	//base case
	if(node == dest){
		path += to_string(node);
		paths.pb({cost, path});
		return;
	}
	//recursive case
	visited[node] = 1;
	for(auto child:g[node]){
		if(!visited[child.fi]){
			dfs(child.fi, path + to_string(node), cost + child.si, visited);
		}
	}
	visited[node] = 0;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    cin>>n>>m;
    g = vector<vector<pair<int, int>>>(n);
    for(int i=0; i<m; i++){
    	int x, y, w;
    	cin>>x>>y>>w;
    	g[x].pb({y, w});
    	g[y].pb({x, w});
    }
    cin>>src>>dest;
    cin>>criteria>>k;
    vector<bool> visited(n, 0);
    dfs(src, "", 0, visited);
    sort(paths.begin(), paths.end());
    n = paths.size() - 1;
    pair<int, string> srch({criteria, ""});
    auto x = paths.begin();
    while(x->fi < criteria){x++;}
    cout<<"Smallest Path = "<<paths[0].si<<"@"<<paths[0].fi<<"\n";
    cout<<"Largest Path = "<<paths[n].si<<"@"<<paths[n].fi<<"\n";
    cout<<"Just Larger Path than "<<criteria<<" = "<<x->si<<"@"<<x->fi<<"\n";
    x--;
    cout<<"Just Smaller Path than "<<criteria<<" = "<<x->si<<"@"<<x->fi<<"\n";
    cout<<k<<"th Largest path = "<<paths[k-1].si<<"@"<<paths[k-1].fi<<"\n";
    for(auto x:paths){
    	cout<<x.fi<<" "<<x.si<<endl;
    }
}
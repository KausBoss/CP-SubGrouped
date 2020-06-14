/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
vector<vector<int>> g;
vector<vector<int>> tg;
vector<bool> visited;
stack<int> s;

void dfs1(int node){
	::visited[node] = true;
	for(auto child:g[node]){
		if(!visited[child]){
			dfs1(child);
		}
	}
	s.push(node);
}

void dfs2(int node, vector<int> &temp){
	visited[node] = 0;
	for(auto child:tg[node]){
		if(::visited[child]){
			cout<<node<<" "<<child<<endl;
			dfs2(child, temp);
		}
	}
	temp.pb(node);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin>>n>>m;
	while(n || m){
		vector<vector<int>> comp;
		g = vector<vector<int>> (n);
		tg= vector<vector<int>> (n);
		visited = vector<bool>(n, false);

		for(int i=0; i<m; i++){
			int u, v;
			cin>>u>>v;
			u--;v--;
			g[u].pb(v);
			tg[v].pb(u);
		}
		for(int i=0; i<n; i++){
			if(!visited[i]){
				dfs1(i);
			}
		}
		while(!s.empty()){
			int node = s.top();
			s.pop();
			if(visited[node]){
				vector<int> temp;
				dfs2(node, temp);
				comp.pb(temp);
				temp.clear();
			}
		}
		int ans=0;
		for(auto x:comp){
			for(auto y:x){
				cout<<y<<" ";
			}
			cout<<endl;
		}
		for(int i=0; i<comp.size(); i++){
			if(comp[i].size() == 1){
				ans++;
			}
		}
		cout<<endl<<endl;
		g.clear(); tg.clear(); visited.clear(); comp.clear();
		cin>>n>>m;
	}
}
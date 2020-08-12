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

void func(){
	ll n, m, x, y;
	cin>>n>>m>>x>>y;
	set<ll> row[n], col[m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			row[i].insert(j);
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			col[i].insert(j);
		}
	}
	cout<<x<<" "<<y<<endl;
	x--;y--;
	row[x].erase(y);
	col[y].erase(x);
	while(!row[x].empty() || !col[y].empty()){
		while(!row[x].empty()){
			cout<<x+1<<" "<<*row[x].begin()+1<<endl;
			y = *row[x].begin();
			row[x].erase(row[x].begin());
			col[*row[x].begin()].erase(x);
		}
		while(!col[y].empty()){
			cout<<*col[y].begin()+1<<" "<<y+1<<endl;
			x = *col[y].begin();
			col[y].erase(*col[y].begin());
			row[*col[y].begin()].erase(y);
		}
	}
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;//cin>>t;
	while(t--){
		func();
	}
}
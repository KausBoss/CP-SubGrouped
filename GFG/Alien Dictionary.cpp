
/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
#define vi 			 vector<int>
#define pb           push_back
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

#define fi first
#define si second
string findOrder(string dict[], int n, int k){
	map<char, list<char>> g;
	map<char, int> indegree;
	for(int i=0; i<k; i++){g['a'+i]={};}
	for(int i=1; i<n; i++){
		string w1 = dict[i-1];
		string w2 = dict[i];
		for(int j=0; j<w1.length() && j<w2.length(); j++){
			if(w1[j] != w2[j]){
				g[w1[j]].push_back(w2[j]);
				cout<<"Pushing "<<w2[j]<<" to "<<w1[j]<<endl;	
				indegree[w2[j]]++;
				break;
			}
		}
	}
	int done =0 ;
	queue<char> q;
	for(auto x:g){
		if(indegree.count(x.fi) == 0){
			q.push(x.fi);
		}
	}
	while(!q.empty()){
		char node = q.front();
		q.pop();
		done++;
		for(auto child:g[node]){
			indegree[child]--;
			if(indegree[child]==0){q.push(child);}
		}
	}
	if(done == k){
		return "1";
	}
	return "0";
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;//cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string dict[n];
		F(dict, n);
		cout<<findOrder(dict, n, k);
	}
}
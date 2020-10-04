/*

*/
#include <bits/stdc++.h>

using namespace std;

#define int           		long long int
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

static bool endtime(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
	return a.si.si < b.si.si;
}

void func(){
	int n;
	cin>>n;
	vector< pair<int, pair<int, int>>> timing(n);
	for(int i=0; i<n; i++){
		cin>>timing[i].si.fi;
		timing[i].fi = i+1;
	}
	for(int i=0; i<n; i++){
		cin>>timing[i].si.si;
	}
	sort(timing.begin(), timing.end(), endtime);
	int endingIn = -1;
	for(int i=0; i<n; i++){
		// cout<<timing[i].fi<<" "<<timing[i].si.fi<<" "<<timing[i].si.si<<endl;
		if(timing[i].si.fi >= endingIn){
			cout<<timing[i].fi<<" ";
			endingIn = timing[i].si.si;
		}
	}
	cout<<endl;
}

int32_t main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}
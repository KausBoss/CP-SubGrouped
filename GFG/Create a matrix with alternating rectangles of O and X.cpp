/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
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

void func(int n){
	vector<vector<char>> a(n, vector<char>(n));
	for(int i=0; i<n/2; i++){
		char ch = 'X';
		int twitch=0;
		for(int j=0; j<=n/2; j++){
			a[i][j] = ch;
			a[n-1-i][j] = ch;
			a[i][n-1-j] = ch;
			a[n-1-i][n-1-j] = ch;
			if(twitch < i){
				twitch++;
				if(ch == 'X'){ch='O';}
				else{ch='X';}
			}
		}
	}
	if(n&1){
		int i = n/2;
		char ch = 'X';
		for(int j=0; j<n; j++){
			a[i][j] = ch;
			if(ch == 'X'){ch='O';}
			else{ch='X';}
		}
	}
	PNF(a, n, n);
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		int n;
		cin>>n;
		func(n);
	}
}
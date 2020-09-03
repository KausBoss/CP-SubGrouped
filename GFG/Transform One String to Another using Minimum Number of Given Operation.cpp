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

int func(string a, string b){
	int n = a.length();
	if(n != b.length()){
		return -1;
	}
	int freqA[26]={0};
	int freqB[26]={0};
	for(int i=0; i<n; i++){
		freqA[a[i]-'A']++;
		freqB[b[i]-'A']++;
	}
	for(int i=0; i<26; i++){
		if(freqA[i] != freqB[i]){
			return -1;
		}
	}
	int res = 0;
	for(int i=n-1, j=n-1; i>=0;){
		while(i>=0 && a[i]!=b[j]){
			i--;
			res++;
		}
		if(i>=0){
			i--;j--;
		}
	}
	return res;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;//cin>>t;
	while(t--){
		string A = "EACBD"; 
    	string B = "EABCD"; 
		cout<<func(A, B);
	}
}
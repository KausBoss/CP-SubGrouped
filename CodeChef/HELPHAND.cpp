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

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	static int count[1000001];
	const int n= 1e6;
	int cnt = 0;
	bitset<n+1> prime;
	for(int p=2; p*p<=n; p++){
		if(!prime[p]){
			for(int i=p*p; i<=n; i+= p){
				prime[i] = 1;
			}
		}
	}
	for(int i=2; i<n+1; i++){
		if(!prime[i]){cnt++;}
		count[i] = cnt;
	}
	int t=1;cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<5){
			cout<<n-1<<"\n";
			continue;
		}
		cout<<n + count[n] - 3<<"\n";
	}
}
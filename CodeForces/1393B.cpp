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
	ll n, q, sq=0, reqS=0;
	cin>>n;
	ll *a = new ll[n];
	F(a, n);
	ll len[(int)1e5 + 5]={0};
	for(int i=0; i<n; i++){
		len[a[i]]++;
	}
	for(int i=1; i<(int)1e5+5; i++){
		sq += (len[i]/4);
		reqS += ((len[i]%4)/2);
	}
	cin>>q;
	while(q--){
		char s;
		ll x;
		cin>>s>>x;
		if(s == '+'){
			len[x]++;
			if(len[x]%4 ==0){
				reqS--;
				sq++;
			}
			else if(len[x]%2 == 0){
				reqS++;
			}

		}
		else{
			len[x]--;
			if(len[x]%4 == 3){
				sq--;
				reqS++;
			}
			else if(len[x]%2 == 1){
				reqS--;
			}
		}
		if(sq >= 2 || (sq && reqS>=2)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
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
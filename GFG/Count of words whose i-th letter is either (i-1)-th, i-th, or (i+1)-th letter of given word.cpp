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
string s;
int n;


void func(int i, string ans=""){
	//base case
	if(i == n){
		cout<<ans<<" ";
		return;
	}
	//recurisve case
	if(i == 0){
		ans += s[0];
		func(i+1, ans);
		ans.pop_back();
		if(i != n-1){
			ans += s[1];
			func(i+1, ans);
			ans.pop_back();
		}
	}
	else if(i != n-1){
		ans += s[i+1];
		func(i+1, ans);
		ans.pop_back();
		ans += s[i];
		func(i+1, ans);
		ans.pop_back();
		ans += s[i-1];
		func(i+1, ans);
		ans.pop_back();
	}
	else{
		ans += s[i];
		func(i+1, ans);
		ans.pop_back();
		ans += s[i-1];
		func(i+1, ans);
		ans.pop_back();
	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;//cin>>t;
	while(t--){
		cin>>s;
		n = s.length();
		func(0);
	}
}
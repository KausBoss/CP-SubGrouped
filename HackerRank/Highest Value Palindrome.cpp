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

string func(string s, int n, int k){
	int i=0, j=n-1;
	vector<bool> chng(n , 0);
	while(i < j){
		if(s[i] != s[j]){
			char ch = max(s[i], s[j]);
			s[i] = ch;
			s[j] = ch;
			chng[i] = 1;
			k--;
		}
		i++;j--;
	}
	if(k < 0){
		return "-1";
	}
	i=0, j=n-1;
	while(k>0 && i < j){
		if(s[i]!='9' && (chng[i] || (!chng[i] && k>1))){
			s[i] = '9';
			s[j] = '9';
			k--;
			if(!chng[i]){
				k--;
			}
		}
		i++;j--;
	}
	if(k && n&1){
		s[n/2] = '9';
	}
	return s;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;//cin>>t;
	while(t--){
		string s;
		int n, k;
		cin>>n>>k;
		cin>>s;
		cout<<func(s, n, k)<<endl;
	}
}
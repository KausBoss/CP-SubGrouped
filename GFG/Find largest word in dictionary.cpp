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

bool srtFunc(string a, string b){
	return a.length() > b.length();
}

void func(){
	int n;
	cin>>n;
	string s[n];
	F(s, n);
	string str;
	cin>>str;
	int fStr[26]={0};
	for(auto x: str){
		fStr[x - 'a']++;
	}
	int id = -1;
	sort(s, s + n, srtFunc);
	for(int i=0; i<n; i++){
		int f[26]={0};
		for(auto x:s[i]){
			f[x - 'a']++;
		}
		bool candidate=true;
		for(int i=0; i<26; i++){
			if(f[i] > fStr[i]){
				candidate=0;
				break;
			}
		}
		if(candidate){
			cout<<s[i]<<endl;
			return;
		}
	}
	cout<<s[id]<<endl;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}
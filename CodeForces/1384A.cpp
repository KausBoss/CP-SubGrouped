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
	ll n, *a;
	cin>>n;
	a = new ll[n];
	F(a, n);
	vector<string> s(n+1, "");
	s[0] = string(a[0], 'a');
	if(a[0] == 0){
		s[0] = "kaustubh";
	}
	for(int i=1; i<n; i++){
		if(a[i] == 0){
			if(a[i-1] == 0){
				int len = s[i-1].length();
				char ch = s[i-1][0];
				if(ch == 'z'){ch='a';}
				else{ch++;}
				s[i] = string(200, ch);
			}
			else{
				s[i] = s[i-1].substr(0, a[i-1]);
			}
		}
		else if(a[i] > a[i-1]){
			s[i] = s[i-1].substr(0, a[i-1]);
			char ch = s[i-1].back();
			if(ch == 'z'){ch='a';}
			else{ch++;}
			string t((a[i]-a[i-1]), ch);
			s[i] += t;
		}
		else if(a[i] <= a[i-1]){
			s[i] = s[i-1].substr(0, a[i-1]);
		}
	}
	s[n] = s[n-1].substr(0, a[n-1]);
	if(a[n-1] == 0){s[n]="tripathi";}
	for(int i=0; i<n+1; i++){
		cout<<s[i]<<endl;
	}
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}
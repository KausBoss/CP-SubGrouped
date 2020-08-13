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
	int n;
	cin>>n;
	vector<string> s(n);
	F(s, n);
	multiset<pair<string, int>> sett;
	for(int i=0; i<n; i++){
		sett.insert({s[i], i});
	}
	int q;cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int id;
			char ch;
			cin>>id;
			cin>>ch;
			id--;
			string nai = s[id] + ch;
			sett.erase({s[id], id});
			s.pb(nai);
			sett.insert({nai, (s.size()-1)});
		}
		else if(t == 2){
			cout<<(*sett.begin()).si +1 <<endl;
			cout<<(*sett.begin()).fi<<endl;
		}
		else{
			auto pt = sett.end();
			pt--;
			cout<<(*pt).si + 1<<endl;
		}
	}
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
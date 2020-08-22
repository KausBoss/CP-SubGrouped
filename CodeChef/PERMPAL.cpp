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

void func(){
	string s;
	deque<int> p;
	cin>>s;
	int n = s.length();
	vector<vector<int>> f(26);
	for(int i=0; i<n; i++){
		f[s[i] - 'a'].pb(i);
	}
	bool oddF = 0;
	int oddPoss=-1;
	for(int i=0; i<26; i++){
		if(f[i].size() & 1){
			if(oddF){
				cout<<-1<<"\n";
				return;
			}
			oddF = 1;
			oddPoss = i;
		}
	}
	if(!(n&1) && oddF){
		cout<<-1<<endl;
		return;
	}
	if(oddF){
		p.push_back(f[oddPoss].back());
		f[oddPoss].pop_back();
	}

	for(int i=0; i<26;i++){
		if(f[i].size()){
			while(f[i].size() > 0){
				p.push_back(f[i].back());
				f[i].pop_back();
				p.push_front(f[i].back());
				f[i].pop_back();
			}
		}
	}
	while(!p.empty()){
		cout<<p.front() + 1<<" ";
		p.pop_front();
	}
	cout<<endl;
}

int main(){
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
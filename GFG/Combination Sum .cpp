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
int n, a[12], b;
set<vector<int>> s;

void print(vector<int> v){
	int n = v.size();
	cout<<"(";
	for(int i=0; i<n; i++){
		cout<<v[i];
		if(i!=n-1){cout<<" ";}
	}
	cout<<")";
}

void func(int i, int b, vector<int> v){
	//base case
	if(b == 0){
		s.insert(v);
		return;
	}
	if(i == n){return;}
	//recursive case
	if(i!=0 && a[i]==a[i-1]){func(i+1, b, v);}

	for(int j=i; a[j]<=b && j<n; j++){
		v.pb(a[j]);
		func(j, b-a[j], v);
		v.pop_back();
	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		cin>>n;
		F(a, n);
		cin>>b;
		sort(a, a+n);
		func(0, b, {});
		if(s.empty()){
			cout<<"Empty";
		}
		for(auto x:s){
			print(x);
		}
		cout<<endl;
		s.clear();
	}
}
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

ll ask(ll a, ll b){
	ll res;
	cout<<"? "<<a<<" "<<b<<endl;
	cin>>res;
	return res;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	ll n;
	cin>>n;
	vector<ll> a(n+1, -1);
	int i=1, j=n;
	while(i < j){
		while(i<j && a[i]!=-1){i++;}
		while(j>i && a[j]!=-1){j--;}
		ll op1 = ask(i, j);
		ll op2 = ask(j, i);
		if(op1 > op2){
			a[i] = op1;
			i++;
		}
		else{
			a[j] = op2;
			j--;
		}
	}
	vector<bool> present(n+1, 0);
	for(int k=1; k<=n; k++){
		if(a[k]!=-1){
			present[a[k]]=1;
		}
	}
	for(int k=1; k<=n; k++){
		if(present[k]==0){
			a[j] = k;
			break;
		}
	}
	cout<<"! ";
	P1(a, n);
}
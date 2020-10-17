/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;

ll fastExp(ll a, ll b, ll y){
	ll res =1;
	while(b){
		if(b&1){
			if(res * a > y){
				return -1;
			}
			res *= a;
		}
		if(a*a > y){return -1;}
		a *= a;
		b /= 2;
	}
	return res;
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	ll x, y, a, b;
	cin>>x>>y>>a>>b;
	ll op1, op2;
	ll s=0, e = y/b;
	while(s <= e){
		ll mid = (s+e)/2;
		ll val = (x + mid*b) > y ? y+1: (x + mid*b);
		if(val > y){
			e = mid -1;
		}
		else{
			op1 = mid;
			s = mid +1;
		}
	}
	s = 0, e=y;
	while(s <= e){
		ll mid = (s+e)/2;
		ll val = fastExp(a, mid, y);
		if(val !=-1 && val*x <y){
			val *= x;
		}
		cout<<mid<<" "<<val<<endl;
		if(val==-1 || val > y){
			e = mid -1;
		}
		else{
			op2 = mid;
			s = mid +1;
		}
	}
	cout<<max(op1, op2);
}
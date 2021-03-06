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

ll n, l, *a;

bool sol(double mid){
	ll speed = 1;
	double pos=0, dist=0, time = mid;
	for(int i=0; i<n; i++){
		double next  = (double)(a[i] - pos)/ speed;
		if(next > time){break;}
		dist += a[i] - pos;
		pos = a[i];
		time -= next;
		speed++;
	}
	dist += (time)*speed;
	pos = l; time = mid; speed = 1;
	for(int i=n-1; i>=0; i--){
		double next  = (double)(pos - a[i])/speed;
		if(next > time){break;}
		dist += pos - a[i];
		pos = a[i];
		time -= next;
		speed++;
	}
	dist += (time)*speed;
	return dist >= l;
}

void func(){
	cin>>n>>l;
	a = new ll[n];
	F(a, n);
	double s=0, e=l, ans;
	while(e - s > (double)1e-6){
		double mid = (s+e)/2;
		bool val = sol(mid);
		if(val){
			ans = mid;
			e = mid;
		}
		else{
			s = mid;
		}
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
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
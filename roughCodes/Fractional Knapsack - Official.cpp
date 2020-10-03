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

bool func(pair<float, float> a, pair<float, float> b){
	return (a.fi/a.si) > (b.fi/b.si);
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int n;
	float cap, ans=0;
	cin>>n;
	vector<pair<float, float>> items(n);//<val, weight>
	for(int i=0; i<n; i++){cin>>items[i].fi;}
	for(int i=0; i<n; i++){cin>>items[i].si;}

	cin>>cap;
	sort(items.begin(), items.end(), func);
	// for(int i=0; i<n; i++){
	// 	cout<<items[i].fi<<" "<<items[i].si<<" "<<items[i].fi / items[i].si<<endl;

	// }
	for(int i=0; i<n; i++){
		if(cap == 0){break;}
		float curWeight = min(items[i].si, cap);
		ans += curWeight * (items[i].fi / items[i].si);
		cap -= curWeight;
	}
	cout<<fixed<<setprecision(10)<<ans;
}
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
int n, a[21], k;

void print(vector<vector<int>> rooms){
	for(auto x:rooms){
		cout<<"[";
		for(int i=0; i<x.size(); i++){
			cout<<x[i];
			if(i!=x.size()-1){cout<<", ";}
		}
		cout<<"] ";
	}
	cout<<endl;
}

void func(int num, int pos, vector<vector<int>> rooms, int sums[]){
	//base case
	if(num == n){
		for(int i=1; i<k; i++){if(sums[i] != sums[0]){return;}}
		print(rooms);
		return;
	}
	//recursive case
	if(num == 0){
		rooms[0].pb(a[num]);
		sums[0] += a[num];
		func(num+1, pos, rooms, sums);
	}
	else{
		for(int i=0; i<=min(pos+1,k-1); i++){
			rooms[i].pb(a[num]);
			sums[i] += a[num];
			func(num+1, max(pos, i), rooms, sums);
			rooms[i].pop_back();
			sums[i] -= a[num];
		}
	}
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	cin>>n;
	F(a, n);
	cin>>k;
	int sum=0;
	for(int i=0; i<n; i++){sum += a[i];}
	if(n<k || n==0 || k==0 || sum%k!=0){
		cout<<-1;
		return 0;
	}
	vector<vector<int>> rooms(k);
	int sums[k] = {0};
	func(0, 0, rooms, sums);
}
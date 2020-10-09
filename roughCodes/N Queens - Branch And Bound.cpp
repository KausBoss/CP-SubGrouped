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
int n, mat[11][11];

void print(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j] == 1){
				cout<<i<<"-"<<j<<", ";
			}
		}
	}
	cout<<".\n";
}

bool possible(int i, int j){
	for(int k=0; k<i; k++){
		if(mat[k][j] == 1){return 0;}
	}
	int k=i, l=j;
	while(k>=0 && l>=0){
		if(mat[k][l] == 1){return 0;}
		k--; l--;
	}
	k=i; l=j;
	while(k>=0 && j<n){
		if(mat[k][l] == 1){return 0;}
		k--; l++;	
	}
	return 1;
}

bool func(int i){
	//base case
	if(i == n){
		print();
		return 0;
	}
	//recursize case
	for(int j=0; j<n; j++){
		if(possible(i, j)){
			mat[i][j] = 1;
			bool next = func(i+1);
			if(next){
				return 1;
			}
			mat[i][j] = 0;
		}
	}
	return 0;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	cin>>n;
	mem(mat, 0);
	func(0);
}
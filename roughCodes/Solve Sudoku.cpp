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
int mat[9][9];

bool possible(int i, int j, int k){
	//check row and col
	for(int it=0; it<9; it++){
		if(mat[it][j]==k || mat[i][it]==k){return 0;}
	}
	//check for 3x3 sub matrix
	int rowStart = (i/3)*3;
	int colStart = (j/3)*3;
	for(int ii=rowStart; ii<rowStart+3; ii++){
		for(int jj=colStart; jj<colStart+3; jj++){
			if(mat[ii][jj]==k){return 0;}
		}
	}
	return 1;
}

bool func(int i, int j){
	//base case
	if(i==9){
		PNF(mat, 9, 9);
		return 1;
	}
	if(j==9){return func(i+1, 0);}
	if(mat[i][j]!=0){return func(i, j+1);}
	//recursive case
	for(int k=1; k<=9; k++){
		if(possible(i, j, k)){
			mat[i][j] = k;
			bool next = func(i, j+1);
			if(next){return 1;}
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
	NF(mat, 9, 9);
	func(0, 0);
}
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
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j];}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;

int dirx[2] = {0, 1};
int diry[2] = {1, 0};
int n;
char mat[10][10];
string s[14];

bool possible(int i, int j, int k, bool dir){
	int m = s[k].length();
	for(int l=0; l<m; l++){
		int ii= i + l*dirx[dir];
		int jj= j + l*diry[dir];
		// cout<<ii<<" "<<jj<<" "<<dir<<endl;
		if(mat[ii][jj]=='+' || (mat[ii][jj]!='-' && mat[ii][jj] != s[k][l]) ){return 0;}
	}
	return 1;
}

void place(int i, int j, int k, bool dir, vector<bool> &myPut){
	int m = s[k].length();
	for(int l=0; l<m; l++){
		int ii= i + l*dirx[dir];
		int jj= j + l*diry[dir];
		myPut[l] = (mat[ii][jj]=='-');
		mat[ii][jj] = s[k][l];
	}
}

void pullOff(int i, int j, int k, bool dir, vector<bool> &myPut){
	int m = s[k].length();
	for(int l=0; l<m; l++){
		int ii= i + l*dirx[dir];
		int jj= j + l*diry[dir];
		if(myPut[l]){mat[ii][jj]='-';}
	}
}

bool func(int k){
	//base case
	if(k == n){
		PNF(mat, 10, 10);
		return 0;
	}
	//recursive case
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if((mat[i][j]=='-' || mat[i][j]==s[k][0]) && (possible(i, j, k, 0)) ){
				vector<bool> myPut(s[k].length(), 0);
				place(i, j, k, 0, myPut);
				bool next = func(k+1);
				if(next){return 1;}
				pullOff(i, j, k, 0, myPut);
			}
			if((mat[i][j]=='-' || mat[i][j]==s[k][0]) && (possible(i, j, k, 1)) ){
				vector<bool> myPut(s[k].length(), 0);
				place(i, j, k, 1, myPut);
				bool next = func(k+1);
				if(next){return 1;}
				pullOff(i, j, k, 1, myPut);
			}
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
	NF(mat, 10, 10);
	cin>>n;
	F(s, n);
	func(0);
}
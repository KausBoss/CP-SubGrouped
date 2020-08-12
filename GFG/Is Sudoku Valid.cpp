/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
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
int a[9][9];


bool possible(int row, int col, int num){
	for(int i=0; i<9; i++){
		if(a[row][i] == num || a[i][col] == num){
			return false;
		}
	}
	int boxR = (row/3)*3;
	int boxC = (col/3)*3;

	for(int i=boxR; i<boxR+3; i++){
		for(int j=boxC; j<boxC+3; j++){
			if(a[i][j] == num){
				return false;
			}
		}
	}
	// cout<<"Placing "<<num<<" at "<<row<<" "<<col<<endl;
	return 1;
}


bool sudoku(int i, int j){
	// cout<<i<<" "<<j<<endl;
	//base case
	if(i == 9){
		return 1;
	}
	if(j == 9){
		return sudoku(i+1, 0);
	}
	if(a[i][j] != 0){return sudoku(i, j+1);}
	//recursive case
	for(int num=1; num<10; num++){
		if(possible(i, j, num)){
			a[i][j] = num;
			bool next = sudoku(i, j+1);
			if(next){
				return true;
			}
			a[i][j]=0;
		}
	}
	return false;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;cin>>t;
	while(t--){
		NF(a, 9, 9);
		// PNF(a, 9, 9);
		cout<<sudoku(0, 0)<<endl;
	}
}
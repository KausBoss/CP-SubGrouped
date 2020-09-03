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
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
char a[21][21];
bool visited[21][21];
bool visited2[21][21];
int n, m;

int mx[4]={1, -1, 0, 0};
int my[4]={0, 0, -1, 1};

bool dfs(int i, int j){
	visited[i][j] = 1;
	if(i==0||i==n-1||j==0||j==m-1){return 0;}
	bool change = 1;
	for(int k=0; k<4; k++){
		int ii = i + mx[k];
		int jj = j + my[k];
		if(a[ii][jj] =='O' && visited[ii][jj]==0){
			change = change & dfs(ii, jj);
		}
	}
	return change;
}

void change_dfs(int i, int j){
	visited2[i][j] = 1;
	a[i][j] = 'X';
	for(int k=0; k<4; k++){
		int ii = i + mx[k];
		int jj = j + my[k];
		if(a[ii][jj] =='O' && visited2[ii][jj]==0){
			change_dfs(ii, jj);
		}
	}
}


void func(){
	cin>>n>>m;
	NF(a, n, m);
	mem(visited, 0);
	mem(visited2, 0);
	for(int i=1; i<n-1; i++){
		for(int j=1; j<m-1; j++){
			if(a[i][j] == 'O' && visited[i][j]==0){
				bool shallwe = dfs(i, j);
				if(shallwe){
					change_dfs(i, j);
				}
			}
		}
	}
	PNF(a, n, m);
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
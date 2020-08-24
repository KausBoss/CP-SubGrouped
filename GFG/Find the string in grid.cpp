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
char g[100][100];
int n, m, l;
string s;
bool poss=0;

int dirX[]={0, 0, 1, -1, 1, -1, 1, -1};
int dirY[]={1, -1, 0, 0, 1, -1, -1, 1};

void func2(int i, int j){
	for(int d=0; d<8; d++){
		int k;
		// cout<<"direction is "<<d<<endl;
		for(k=0; k<l; k++){
			int ii = i + dirX[d]*k;
			int jj = j + dirY[d]*k;
			// cout<<ii<<" "<<jj<<endl;
			if(ii<0 || ii==n || jj<0 || jj==m){break;}
			if(s[k] != g[ii][jj]){break;}
		}
		// cout<<"K is "<<k<<endl;
		if(k == l){
			poss = 1;
			cout<<i<<" "<<j<<", ";
			return;
		}
	}
}


void func(int i, int j){
	// cout<<i<<" "<<j<<" "<<k<<endl;
	//base case
	if(i==n){return;}
	if(j==m){
		func(i+1, 0);
		return;
	}
	//recursive case
	if(g[i][j] == s[0]){
		func2(i, j);
	}
	func(i, j+1);
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		poss= 0;
		cin>>n>>m;
		NF(g, n, m);
		cin>>s;
		l = s.length();
		func(0, 0);
		if(!poss){
			cout<<-1;
		}
		cout<<endl;
		// PNF(g, n, m);
	}
}
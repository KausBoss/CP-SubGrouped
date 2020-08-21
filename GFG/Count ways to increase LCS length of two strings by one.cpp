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
ll lcsP[104][104], lcsS[104][104];
ll n, m;
string a, b;

void fillMatrix(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1] == b[j-1]){
				lcsP[i][j] = 1 + lcsP[i-1][j-1];
			}
			else{
				lcsP[i][j] = max(lcsP[i-1][j], lcsP[i][j-1]);
			}
		}
	}

	for(int i=n; i>0; i--){
		for(int j=m; j>0; j--){
			if(a[i-1] == b[j-1]){
				lcsS[i][j] = 1 + lcsS[i+1][j+1];
			}
			else{
				lcsS[i][j] = max(lcsS[i+1][j], lcsS[i][j+1]);
			}
		}
	}
}


void func(){
	cin>>n>>m;
	n--;
	cin>>a>>b;
	mem(lcsP, 0);
	mem(lcsS, 0);
	fillMatrix();
	int ans=0, total = lcsP[n][m];
	// PNF(lcsP, n+1, m+1);
	// PNF(lcsS, n+1, m+1);
	for(int i=0; i<n; i++){
		for(int k=0; k<26; k++){
			char ch = 'a' + k;
			for(int j=0; j<m; j++){
				if(b[j] == ch){	
					if (lcsP[i][j] + lcsS[i+1][j] == total){
						ans++;
					} 
				}
			}
		}
	}
	cout<<ans<<endl;
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
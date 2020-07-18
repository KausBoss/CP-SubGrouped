/*

*/
#include <bits/stdc++.h>

using namespace std;

#define int          long long int
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


bool bc(pair<int,int> a, pair<int,int> b){
	return a.fi > b.fi;
}
bool bcc(int a, int b){
	return a>b;
}

int32_t main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n, totw=0;
	cin>>n;
	vi uno, dos;
	for(int i=0; i<n; i++){
		int t, w;
		cin>>t>>w;
		totw += w;
		if(t == 1){uno.pb(w);}
		else{dos.pb(w);}
	}
	sort(dos.begin(), dos.end(), bcc);
	sort(uno.begin(), uno.end(), bcc);
	int totT=0, i=0, j=0;
	while(totT < totw){
		if(j == uno.size()){
			totw -= dos[i++];
			totT+=2;
		}
		else if(i == dos.size()){
			totw -= uno[j++];
			totT++;
		}
		else if(j < uno.size() && totw - uno[j] <= totT+1){
			cout<<totT+1;
			return 0;
		}
		else if(i < dos.size() && totw-dos[i] == totT + 2){
			cout<<totT + 2;
			return 0;
		}
		else if(j < uno.size() && uno[j] >= dos[i]){
			totw -= uno[j++];
			totT++;
		}
		else if(j+1 < uno.size() && uno[j] + uno[j+1] > dos[i]){
			totw -= uno[j++];
			totw -= uno[j++];
			totT += 2;
		}
		else{
			totw -= dos[i++];
			totT +=2;
		}
		// cout<<i<<" "<<j<<" "<<totw<<" "<<totT<<endl;
	}
	cout<<totT;
}
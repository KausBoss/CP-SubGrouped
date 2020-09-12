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

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	ll n;
	cin>>n;
	string s;
	cin>>s;
	vector<bool> c(n, 0), t(n, 0), ca(n, 0), at(n, 0);
	c[0] = (s[0]=='c');
	for(int i=1; i<n; i++){
		c[i] = c[i-1];
		if(s[i]=='c'){c[i]=1;}
		ca[i] = ca[i-1];
		if(s[i]=='a'){ca[i] = c[i];}
	}
	t[n-1] = (s[n-1]=='t');
	for(int i=n-2; i>=0; i--){
		t[i] = 1;
		if(s[i]=='t'){t[i]=1;}
		at[i] = at[i+1];
		if(s[i]=='a'){at[i] =t[i];}
	}
	int delC=0, delA=0, delT=0;
	vector<bool> pres(n, 1);
	for(int i=0; i<n; i++){
		if(s[i]=='c' && at[i]>0){
			delC++;
			pres[i] = 0;
		}
		else if(s[i]=='a' && c[i]>0 && t[i]>0){
			delA++;
			pres[i] = 0;
		}
		else if(s[i]=='t' && ca[i]>0){
			delT++;
			pres[i] = 0;
		}
	}
	int out = min(delC, min(delA, delT));
	char ch;
	if(out == delC){ch = 'c';}
	else if(out == delA){ch = 'a';}
	else{ch = 't';}
	cout<<n-out<<endl;
	for(int i=0; i<n; i++){
		if(s[i]==ch && pres[i]==0){
			continue;
		}
		cout<<s[i];
	}
}
/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
#define mp           make_pair
#define pb           push_back
#define fi           first
#define si           second
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i];}cout<<endl;
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;

void func(){
	string s;
	cin>>s;
	int n = s.length();
	int pos[3] = {0};
	for(int i=0; i<n; i++){
		if(s[i] == 'S'){
			pos[0]++;
		}
		else if(s[i] == 'R'){
			pos[1]++;
		}
		else{
			pos[2]++;
		}
	}
	if(pos[0] >= pos[1] && pos[0] >= pos[2]){
		vector<char> op(n, 'R');
		P(op, n);
		return;
	}
	else if(pos[1] >= pos[0] && pos[1] >= pos[2]){
		vector<char> op(n, 'P');
		P(op, n);
		return;
	}
	vector<char> op(n, 'S');
	P(op, n);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin>>t;
	while(t--){
		func();
	}
}
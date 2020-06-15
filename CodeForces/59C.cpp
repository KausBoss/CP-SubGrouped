/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int k;
	string s;
	cin>>k;
	cin>>s;
	bitset<26> present;
	int n = s.length();
	int i = 0, j = n - 1;
	while(i<=j){
		if(s[i] == '?' && s[j] != '?'){
			s[i] = s[j];
		}
		else if(s[i] != '?' && s[j] == '?'){
			s[j] = s[i];
		}
		else if(s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
			cout<<"IMPOSSIBLE";
			return 0;
		}
		if(s[i] != '?'){present[s[i] - 'a']=1;}
		if(s[j] != '?'){present[s[j] - 'a']=1;}
		i++; j--;
	}
	j=k-1;
	//start placing missing letters from inside to outside so that we get 
	//lexiographically the smallest word
	for(int i=((n+1)/2)-1; i>=0; i--){
		while(j>0 && present[j] == 1){
			j--;
		}
		if(s[i] == '?'){
			s[i] = 'a' + j;
			s[n-i-1] = 'a' + j;
			present[j] = 1;
		}
	}
	for(int i=0; i<k; i++){
		if(present[i] == 0){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	cout<<s;
}
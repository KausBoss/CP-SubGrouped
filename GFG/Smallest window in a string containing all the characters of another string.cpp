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

bool checker(vector<int> v){
	for(int i=0; i<26; i++){
		if(v[i] < 0){
			return 0;
		}
	}
	return 1;
}

void func(){
	string s, t;
	cin>>s;
	cin>>t;
	vector<int> freq(26, 0);
	for(int i=0; i<t.length(); i++){
		freq[t[i] - 'a']--;
	}
	int j=0, ans=1e5, start;
	for(int i=0; i<s.length(); i++){
		freq[s[i] - 'a']++;
		while(freq[s[j]-'a'] > 0){
			freq[s[j]-'a']--;
			j++;
		}
		if(checker(freq) && ans > (i-j+1)){
			ans = i - j + 1;
			start = j;
		}
		// cout<<j<<" "<<i<<" "<<ans<<endl;
	}
	if(ans != (int)1e5){
		cout<<s.substr(start, ans)<<endl;
		return;
	}
	cout<<-1<<endl;
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
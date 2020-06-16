/*
We will construct the string t, starting with the largest letters. 
Note that if bi=0, then the i-th letter of the string t is maximal, 
so we know that the i-th letter affects all bj≠0. While the line t is 
not completely constructed, we will do the following:

Find all i such that bi=0 and the i-th character of string t is not placed;
Put on all these positions i in the string t the maximum letter not used in 
the string t (there should be a sufficient number of letters in the string s);
Subtract |i−j| from all bj≠0.
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


void func(){
	string s;
	int m;
	cin>>s;
	cin>>m;
	vector<int> B(m);
	F(B, m);
	vector<int> freq(26, 0);
	for(int i=0; i<s.length(); i++){
		freq[s[i] - 'a']++;
	}
	priority_queue<pair<char, int>> pq;
	for(int i=0; i<26; i++){
		if(freq[i] > 0){
			pq.push({'a' + i, freq[i]});
		}
	}
	int replaced = 0;
	string ans(m, '.');
	while(replaced < m){
		vector<int> tt;
		for(int i=0; i<m; i++){
			if(B[i] == 0 && ans[i] == '.'){
				tt.pb(i);
			}
		}
		while(pq.top().si < tt.size()){pq.pop();}
		for(auto x:tt){
			for(int j=0; j<m; j++){
					if(B[j] > 0){
						B[j] -= abs(x - j);
					}
			}
			ans[x] = pq.top().fi;
			replaced++;
		}
		pq.pop();
		if(replaced == m){break;}
	}

	cout<<ans<<endl;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}
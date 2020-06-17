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

void Make_table(string p, vector<int> &table){
	int i=0, j=1;
	while(j < p.length()){
		if(p[i] != p[j]){
			if(i == 0){
				j++;
			}
			else{
				i = 0;
			}
		}
		else{
			table[j++] = ++i;
		}
	}
	return;
}

bool KMP(string s, string p, vector<int> table){
	int i = 0, j = 0;
	int ls = s.length();
	int lp = p.length();
	while(i < ls){
		while(j > 0 && s[i] != p[j]){
			j = table[j-1];
		}

		if(s[i] == p[j]){
			i++; j++;
		}
		else{
			i++;
		}

		if(j == lp){
			return true;
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int prev;
		cin>>prev;
		string s, p;
		for(int i=1; i<n; i++){
			int temp;
			cin>>temp;
			if(temp > prev){
				s.pb('G');
			}
			else if(temp < prev){
				s.pb('L');
			}
			else{
				s.pb('E');
			}
			prev = temp;
		}
		cin>>p;
		vector<int> table(p.length(), 0);
		Make_table(p, table);
		if(KMP(s, p, table)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
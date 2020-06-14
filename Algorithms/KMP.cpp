/*
In KMP algo we have to first create a pi table which stores the occurrence
of the prefix of the pattern. This way we are able to store where the 
repetition of the starting elements of the pattern take place in the middle 
of the pattern.
The size of the Pi table is equal to the size of the pattern.

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

//function to initialize the pi table
void table_setup(string p, vector<int> &table){
	int i=0, j=1;//iterators, j starts from 1
	while(j < p.size()){
		if(p[i] != p[j]){
			//if there is a mismatch
			if(i == 0){
				//if i is at 0th index just move j
				j++;
			}
			else{
				//else move i to 0 and check again for same j
				i=0;
			}
		}
		else{
			//if element match tabl[j] becomes i + 1
			table[j++] = ++i;
		}
	}
}

void KMP(string s, string p, vector<int> table){
	int i=0, j=0;
	int ls=s.length();
	int lp=p.length();

	while(i < ls){
		while(j > 0 && s[i] != p[j]){
			j = table[j-1];//if there is a mismatch and j > 0 we go to the value of table[j-1]
		}

		if(s[i] == p[j]){
			i++; j++;//if there is a match increment both iterator
		}
		else{
			i++;//if there is a mismatch and j == 0, increment only i
		}

		if(j == lp){
			//if j == lp then we have found the whole pattern
			cout<<"Found at index "<<i-j<<endl;
			j = table[j-1];
		}
	}
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	string s, p;//s is the strng and p is the pattern
	cin>>p>>s;
	vector<int> table(p.length(), 0);//pi table to store prefix occurence
	table_setup(p, table);
	KMP(s, p, table);
}
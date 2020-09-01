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

string func(int a[], int n){
	vector<pair<string, int>> p;
	for(int i=0; i<n; i++){
		pair<string, int> temp;
		temp.si = a[i];
		bool inc[3] = {0};
		string s = "";
		while(a[i]){
			char ch = '0' + (a[i]%10);
			if(ch=='1' || ch=='2' || ch=='3'){
				s += ch;
				if(ch=='1'){inc[0]=1;}
				else if(ch=='2'){inc[1]=1;}
				else{inc[2]=1;}
			}
			a[i] /= 10;
		}
		if(inc[0] && inc[1] && inc[2]){
			temp.fi = s;
			p.push_back(temp);
		}
	}
	if(p.empty()){return "-1";}
	sort(p.begin(), p.end());
	string ret = "";
	for(auto pr:p){
		ret += pr.fi + ", ";
	}
	return ret;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;//cin>>t;
	while(t--){
		int numbers[] = { 123, 1232, 456, 234, 32145 }; 
  
	    int n = sizeof(numbers)/sizeof(numbers[0]); 
	      
	    string result = func(numbers, n); 
	    cout << result; 
	}
}
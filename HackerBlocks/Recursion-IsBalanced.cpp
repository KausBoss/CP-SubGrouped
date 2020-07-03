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
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
string s;

bool Valid(int i, int curl, int square, int round, char last){
	//base case
	if(i == s.length()){
		return (curl==0 && square==0 && round==0);
	}
	//recursive case
	if(s[i] == '{'){curl++;last=s[i];}
	else if(s[i] =='('){round++;last=s[i];}
	else if(s[i] == '['){square++;last=s[i];}
	else if(s[i] == '}'){if(last != '{')return false;curl--;}
	else if(s[i] == ')'){if(last != '(')return false;round--;}
	else if(s[i] == ']'){if(last != '[')return false;square--;}

	if(curl<0 || square<0 || round<0){
		return false;
	}
	return Valid(i+1, curl, square, round, last);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin>>s;
	if(Valid(0, 0, 0, 0, 'a')){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
}
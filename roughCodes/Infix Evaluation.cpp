/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;

int precedence(char op){
	if(op=='+'){return 1;}
	if(op=='-'){return 1;}
	if(op=='*'){return 2;}
	return 2;
}

int opVal(int v1, int v2, char op){
	if(op=='+'){return v1+v2;}
	if(op=='-'){return v1-v2;}
	if(op=='*'){return v1*v2;}
	return v1/v2;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	string s;
	getline(cin, s);
	stack<int> oprand;
	stack<char> optr;
	for(auto x:s){
		if(x>='0' && x<='9'){
			oprand.push(x-'0');
		}
		else if(x=='('){
			optr.push(x);
		}
		else if(x==')'){
			while(optr.top() != '('){
				char op = optr.top();
				optr.pop();
				int v2 = oprand.top();
				oprand.pop();
				int v1 = oprand.top();
				oprand.pop();
				oprand.push(opVal(v1, v2, op));
			}
			optr.pop();
		}
		else if(x=='+' || x=='-' || x=='*' || x=='/'){
			while(optr.size() && optr.top()!='(' && precedence(optr.top()) >= precedence(x)){
				char op = optr.top();
				optr.pop();
				int v2 = oprand.top();
				oprand.pop();
				int v1 = oprand.top();
				oprand.pop();
				oprand.push(opVal(v1, v2, op));
			}
			optr.push(x);
		}
	}
	while(!optr.empty()){
		char op = optr.top();
		optr.pop();
		int v2 = oprand.top();
		oprand.pop();
		int v1 = oprand.top();
		oprand.pop();
		oprand.push(opVal(v1, v2, op));
	}
	cout<<oprand.top();
}
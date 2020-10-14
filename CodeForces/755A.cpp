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

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int n;
	cin>>n;
	if(n&1){
		cout<<111;
		return 0;
	}
	switch(n%10){
		case 2: cout<<12;
		break;
		case 4: cout<<11;
		break;
		case 6: cout<<14;
		break;
		case 8: cout<<13;
		break;
		case 0: for(int i=1; i<=1000; i++){
			if(((i*n +1) % 3) == 0 && (i*n +1)!=3){cout<<i;break;}
			else if(((i*n +1) % 7 && (i*n +1)!=7) == 0){cout<<i;break;}
			else if(((i*n +1) % 11) == 0 && (i*n +1)!=11){cout<<i;break;}
			else if(((i*n +1) % 13) == 0 && (i*n +1)!=13){cout<<i;break;}
			else if(((i*n +1) % 17) == 0 && (i*n +1)!=17){cout<<i;break;}
		}
	}
}
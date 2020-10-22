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

void func(){
	ll n;
	cin>>n;
	if(n == 1 || n==2 || n==4){
		cout<<-1<<endl;
		return;
	}
	ll three=0, five=0, seven=0;
	five = (n - n%10)/5;
	if(n%10 == 0){
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 1){
		five--;
		three += 2;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 2){
		five--;
		seven++;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 3){
		three++;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 4){
		five -= 2;
		seven += 2;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 5){
		five++;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 6){
		three += 2;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 7){
		seven++;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 8){
		five++;
		three++;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
	if(n%10 == 9){
		three += 3;
		cout<<three<<" "<<five<<" "<<seven<<endl;
		return;
	}
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
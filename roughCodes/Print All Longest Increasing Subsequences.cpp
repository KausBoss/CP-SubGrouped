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

class Node{
public:
	int val, id;
	vector<int> path;
	Node(int val, int id, vector<int> path){
		this->val = val;
		this->id = id;
		this->path = path;
	}
};

void print(vector<int> p){
	for(int i=p.size()-1; i>=0; i--){
		cout<<p[i];
		if(i!=0){cout<<" -> ";}
		else{cout<<endl;}
	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
	freopen("../out.txt","w",stdout);
	#endif
    int n, a[101], omax=0, dp[101];
    cin>>n;
    F(a, n);
    for(int i=0; i<n; i++){
    	dp[i] = 1;
    	for(int j=0; j<i; j++){
    		if(a[i] >= a[j]){
    			dp[i] = max(dp[i], 1 + dp[j]);
    		}
    	}
    	omax = max(omax, dp[i]);
    }
    cout<<omax<<endl;
    queue<Node> q;
    for(int i=0; i<n; i++){
    	if(dp[i] == omax){
    		Node n(omax, i, {a[i]});
    		q.push(n);
    	}
    }
    while(!q.empty()){
    	Node n = q.front();
    	q.pop();
    	if(n.val == 1){
    		print(n.path);
    	}
    	else{
    		for(int i=n.id-1; i>=0; i--){
    			if(dp[i] == (n.val - 1) && a[i] < a[n.id]){
    				vector<int> path_temp(n.path);
    				path_temp.pb(a[i]);
    				Node temp(n.val-1, i, path_temp);
    				q.push(temp);
    			}
    		}
    	}
    }
}
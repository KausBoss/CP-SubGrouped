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

class Node{
	public:
	Node *left, *right;
	Node(){
		left=NULL; right==NULL;
	}
};

class Trie{
	Node *root;
	int maxAns;
public:
	Trie(){
		root = new Node();
		maxAns = 0;
	}
	void insert(int val){
		Node *temp = root;
		for(int i=30; i>=0; i--){
			bool bit = ( (val>>i)&1 );
			if(bit){
				if(temp->right==NULL){temp->right = new Node();}
				temp = temp->right;
			}
			else{
				if(temp->left==NULL){temp->left = new Node();}
				temp = temp->left;
			}
		}
		xor_helper(val);
	}
	void xor_helper(int val){
		int ans = 0;
		Node *temp = root;
		for(int i=30; i>=0; i--){
			bool bit = ( (val>>i)&1 );
			if(bit){
				if(temp->left){ans += (1<<i); temp = temp->left;}
				else{temp = temp->right;}
			}
			else{
				if(temp->right){ans += (1<<i); temp = temp->right;}
				else{temp = temp->left;}
			}
		}
		maxAns = max(maxAns, ans);
	}

	int MaxXor(){return maxAns;}
};



int main(){
		fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    int test;
    cin>>test;
    while(test--){
		int n, a=0;
		Trie t;
		cin>>n;
		t.insert(0);
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			a ^= x;
			t.insert(a);
		}
		cout<<t.MaxXor()<<endl;
    }
}
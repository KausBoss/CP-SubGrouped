/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
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
	int data;
	Node *left;
	Node *right;
	Node(){}
	Node(int data){
		this->data = data;
		left = right = NULL;
	}
	Node (int data, Node *left, Node *right){
		this->data = data;
		this->right = right;
		this->left = left;
	}
};

//Function to buil Tree
Node* Build(){
	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}
	Node *n = new Node(d, Build(), Build());
	return n;
}

//Printing PreOrder of Tree
void prePrint(Node* root){
	//base case
	if(root == NULL){
		return;
	}
	//recursive case
	cout<<root->data<<" ";
	prePrint(root->left);
	prePrint(root->right);
}

//max sum path in tree 
//pair<max sum till now, max sum ans>
pair<int, int> maxSum(Node *root){
	//base case
	if(root == NULL){
		return {0, 0};
	}
	//recursive case
	pair<int,int> ret;

	auto left = maxSum(root->left);
	auto right = maxSum(root->right);

	int mxrn = max(left.si, right.si);
	int d = root->data;
	ret.si = mxrn;

	if(d+left.fi<0 && d+right.fi<0){
		ret.fi =0;
		return ret;
	}
	if(left.fi + right.fi + d > mxrn){
		ret.si = left.fi + right.fi + d;
	}
	ret.fi = d + max(left.fi, right.fi);
	return ret;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	Node* root = Build();
	// prePrint(root);
	cout<<maxSum(root).si;
}
// 4 1 -1 -1 2 3 -1 -1 -1
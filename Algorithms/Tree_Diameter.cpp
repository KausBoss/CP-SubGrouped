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

//Finding Height of the tree

int TreeHeight(Node* root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
}

//Finding Diameter Basic way
int DiameterBasic(Node *root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	int left_height = TreeHeight(root->left);
	int right_height = TreeHeight(root->right);
	int op1 = DiameterBasic(root->left);
	int op2 = DiameterBasic(root->right);
	int op3 = left_height + right_height;

	return max(op1, max(op2, op3));
}

//Faster way to Calculate Diameter (pair<height, diameter>)
pair<int, int> DiameterFast(Node *root){
	//base case
	if(root == NULL){
		return {0, 0};
	}
	//recursive case
	pair<int, int> p;
	auto left = DiameterFast(root->left);
	auto right = DiameterFast(root->right);
	p.fi = 1 + max(left.fi, right.fi);
	p.si = max(left.fi + right.fi, max(left.si, right.si));

	return p;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	Node *root = Build();

	cout<<DiameterBasic(root)<<endl;
	cout<<DiameterFast(root).si;
}
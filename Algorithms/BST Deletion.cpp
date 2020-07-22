/*
# possible cases of deletion in BST-
	1.deleting a node with no children
	2.deleting a node with only one child
	3.deleting a node which has both children
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

//Function to build bST
Node* buildBST(Node *root, int d){
	//base case
	if(root == NULL){
		return new Node(d);
	}
	//recursive case
	if(d <= root->data){
		root->left = buildBST(root->left, d);
	}
	else{
		root->right = buildBST(root->right, d);
	}
	return root;
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

Node* Del(Node *root, int k){
	//base case
	if(root == NULL){
		return NULL;
	}
	//recursive case
	if(root->data > k){
		root->left = Del(root->left, k);
		return root;
	}
	if(root->data == k){
		//case 1. No children or Leaf Node
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}

		//case 2. One children
		if(root->left!=NULL && root->right==NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL){
			Node *temp = root->right;
			delete root;
			return temp;
		}

		//Case 3. Both children
		if(root->left!=NULL && root->right!=NULL){
			Node *rep=root->right;
			while(rep->left != NULL){
				rep = rep->left;
			}
			root->data = rep->data;
			root->right = Del(root->right, rep->data);
		}
	}

	if(root->data < k){
		root->right = Del(root->right, k);
		return root;
	}
	return root;
}


int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	Node* root = NULL;
	vector<int> v{25, 20, 10, 5, 12, 22, 36, 30, 28, 40, 38, 48};
	for(auto x:v){
		root =buildBST(root, x);
	}
	prePrint(root);
	cout<<endl;
	root = Del(root, 25);
	prePrint(root);
}

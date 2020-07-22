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

vector<int> ans;
//premute all nodes at distance k below (helper)
void permute(Node *root, int k){
	//base case
	if(root == NULL){
		return;
	}
	//recursive case
	if(k == 0){
		ans.push_back(root->data);
		return;
	}
	permute(root->left, k-1);
	permute(root->right, k-1);
}

//finding the reference node
int FindNode(Node *root, Node* k, int d){
	//base case
	if(root == NULL){
		return -1;
	}
	//recursive case
	if(root == k){
		permute(root, d);
		return d-1;
	}
	int left = FindNode(root->left, k , d);
	int right = FindNode(root->right, k, d);

	if(left ==-1 && right == -1){
		return -1;
	}
	if(left ==  0 || right == 0){
		ans.pb(root->data);
		return -1;
	}
	if(left != -1){
		permute(root->right, left-1);
		return left-1;
	}
	if(right != -1){
		permute(root->left, right-1);
		return right-1;
	}
	return -1;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	Node* root = Build();
	// prePrint(root);
	Node *k = root->left->right;// k is the reference node
	FindNode(root, k, 5);//last arguement is the distance
	for(auto x: ans){
		cout<<x<<endl;
	}
}
// 4 1 -1 -1 2 3 -1 -1 -1
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

//Function to buil Tree from Inorder and Preorder
Node* Build(int *pre, int *in, int s, int e){
	static int i=0;
	//base case
	if(s > e){
		return NULL;
	}
	//recursive case
	Node* root = new Node(pre[i]);
	int id;
	for(id =s; id<=e; id++){
		if(in[id] == pre[i]){
			break;
		}
	}
	i++;
	root->left = Build(pre, in, s, id-1);
	root->right = Build(pre, in, id+1, e);

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

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int pre[]={3,9,20,15,7};
    int in[]={9,3,15,20,7};
    int n= sizeof(in)/sizeof(int);
	Node* root = Build(pre, in, 0, n-1);
	prePrint(root);
}
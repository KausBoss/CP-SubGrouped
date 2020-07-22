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
		this->left = left;
		this->right = right;
	}
};

//Function to build bST from sorted array
Node* arrayToBST(vector<int> v, int s, int e){
	//base case
	if(s > e){
		return NULL;
	}
	if(s== e){
		return new Node(v[s]);
	}
	//recursive case
	int mid = (s+e)/2;
	Node *n = new Node(v[mid], arrayToBST(v, s, mid-1), arrayToBST(v, mid+1, e));
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

//BFS to print
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *n = q.front();
		q.pop();
		if(n == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<n->data<<" ";
			if(n->left != NULL){
				q.push(n->left);
			}
			if(n->right != NULL){
				q.push(n->right);
			}
		}
	}
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Node *root;
	vector<int> v{25, 20, 10, 5, 12, 22, 36, 30, 28, 40, 38, 48};
	sort(v.begin(), v.end());
	root = arrayToBST(v, 0, v.size()-1);
	BFS(root);
}
// 4 1 -1 -1 2 3 -1 -1 -1
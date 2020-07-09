/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
#define mp           make_pair
#define pb           push_back
#define fi           first
#define si           second
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;

class Node{
public:
	int data;
	Node* next;
	//constructors
	Node(){}
	Node(int data){
		this->data =data;
		next = NULL;
	}
};

void headInsert(Node *&head, int data){
	Node *n= new Node(data);
	n->next = head;
	head = n;
}

Node* middleNode(Node *head){
	Node *slow=head, *fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

Node* tailNode(Node *head){
	while(head->next != NULL){
		head = head->next;
	}
	return head;
}

bool isCycle(Node *head){
	Node *slow=head, *fast=head;

	while(fast != NULL && fast->next !=NULL){
		fast = fast->next->next;
		slow = slow->next;

		if(fast == slow){
			return 1;
		}
	}
	return 0;
}

Node* posCycle(Node *head){
	Node *slow=head, *fast=head;

	while(fast != NULL && fast->next !=NULL){
		fast = fast->next->next;
		slow = slow->next;

		if(fast == slow){
			break;
		}
	}
	while(fast != head){
		fast=fast->next;
		head=head->next;
	}
	return head;
}

void printLL(Node *head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;

}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	    //preparing a Linked List
    Node  *head = NULL;
	//insert at head
	for(int i=0; i<=7; i++){
		headInsert(head, i);
	}
	printLL(head);

	//joinig the last node with the middle node to create cycle
	tailNode(head)->next = middleNode(head);

	//checking for cycle using Flyod's Algorithm
	cout<<isCycle(head)<<endl;

	//returning the point of cycle in Linked List
	cout<<posCycle(head)->data<<endl;
}
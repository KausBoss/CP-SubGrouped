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

int lengthLL(Node *head){
	int length=0;
	while(head != NULL){
		head = head->next;
		length++;
	}
	return length;
}

void headInsert(Node *&head, int data){
	Node *n= new Node(data);
	n->next = head;
	head = n;
}

void tailInsert(Node *head, int data){
	if(head == NULL){
		headInsert(head, data);
		return;
	}
	Node *temp=head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new Node(data);

}

void middleInsert(Node *head, int pos, int data){
	//case 1
	if(head == NULL || pos == 0){
		headInsert(head, data);
		return;
	}
	
	//case 2
	if(pos >= lengthLL(head)){
		tailInsert(head, data);
		return;
	}

	//case 3
	Node *temp = head;
	int len=1;
	while(len < pos-1){
		temp = temp->next;
		len++;
	}
	Node *n = new Node(data);
	n->next = temp->next;
	temp->next = n;
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
	Node  *head = NULL;
	//insert at head
	for(int i=0; i<5; i++){
		headInsert(head, i);
	}
	printLL(head);

	//Insert at tail
	for(int i=0; i<5; i++){
		tailInsert(head, i);
	}
	printLL(head);

	//Insert in Middle
	middleInsert(head, 7, 16);

	printLL(head);
}
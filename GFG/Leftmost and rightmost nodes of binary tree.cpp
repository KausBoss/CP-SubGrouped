/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root){
	if(root == NULL){return;}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	bool st = 1;
	while(!q.empty()){
		Node *n = q.front();
		q.pop();
		if(n == NULL){
			st = 1;
			if(!q.empty()){q.push(NULL);}
			continue;
		}
		if(st){
			cout<<n->data<<" ";
			st = 0;
		}
		else{
			if(q.front() == NULL){
				cout<<n->data<<" ";
			}
		}
		if(n->left){q.push(n->left);}
		if(n->right){q.push(n->right);}
	}
}
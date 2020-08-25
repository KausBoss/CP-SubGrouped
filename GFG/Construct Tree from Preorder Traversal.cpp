/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node* func(int i, int pre[], char preLN[], int n){
	while(i<n && pre[i]==-1){i++;}
	if(i>=n){return NULL;}
	Node *curr = new Node(pre[i]);
	pre[i] = -1;

	if(preLN[i] != 'L'){
		curr->left = func(i+1, pre, preLN, n);
		curr->right = func(i+2, pre, preLN, n);
	}
	return curr;
}

Node *constructTree(int n, int pre[], char preLN[]){
 	return func(0, pre, preLN, n);
}
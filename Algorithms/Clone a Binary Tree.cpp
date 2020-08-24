Node* cloneTree(Node* tree){
	//base case
	if(tree == NULL){
		return NULL;
	}
	Node *n = new Node(tree->data);
	n->left = cloneTree(tree->left);
	n->right = cloneTree(tree->right);
	return n;
}
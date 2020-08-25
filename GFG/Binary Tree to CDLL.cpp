void treeToLL(Node *root, Node **head){
	static Node *prev = NULL;
	//base case
	if(root == NULL){
	    return;
	}
	treeToLL(root->left, head);
	if(!(*head)){
		*head = root;
	}
	else{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	treeToLL(root->right, head);
}

Node *bTreeToCList(Node *root){
     Node *head=NULL;
     treeToLL(root, &head);
     Node *temp = head;
     while(temp->right != NULL){
     	temp = temp->right;
     }
     temp->right = head;
     head->left = temp;
     return head;
}
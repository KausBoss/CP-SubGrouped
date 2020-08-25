void convert(Node *head, TreeNode *&root){
	queue<TreeNode*> q;
	TreeNode* n = new TreeNode(head->data);
	head=head->next;
	q.push(n);
	root = q.front();
	while(!q.empty()){
		TreeNode *n = q.front();
		q.pop();
		if(head){
			TreeNode *left = new TreeNode(head->data);
			n->left = left;
			head = head->next;
			q.push(left);
		}
		if(head){
			TreeNode *right = new TreeNode(head->data);
			n->right = right;
			head = head->next;
			q.push(right);
		}
	}
	return;
}
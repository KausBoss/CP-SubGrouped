void deleteNode(Node *node){
	if(node == NULL){return;}
	node->data = node->next->data;
	if(node->next->next == NULL){
		Node *temp = node->next;
		node->next = NULL;
		delete temp;
		return;
	}
	deleteNode(node->next);
}
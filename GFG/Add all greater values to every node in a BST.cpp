void modify (Node * rt, int &add)
{
    if (rt == NULL) return;
    
    modify (rt->right, add);
    rt->data += add;
    add = rt->data;
    modify (rt->left, add);
}

/*  modifies the root of the bst */
Node* modify(Node *root)
{
    if (root == NULL) return root;
    
    int add = 0;
    modify (root, add);
    return root;
}
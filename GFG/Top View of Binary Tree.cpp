void topView(struct Node *root)
{
    map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(m.count(p.second)==0){m[p.second] = p.first->data;}
        if(p.first->left){q.push({p.first->left, p.second-1});}
        if(p.first->right){q.push({p.first->right, p.second+1});}
    }
    for(auto x:m){
        cout<<x.second<<" "; 
    }
}
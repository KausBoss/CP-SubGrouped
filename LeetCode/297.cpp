class Codec {
public:
    
    constexpr static char DELIMITER = ',';
    constexpr static char NULL_CHAR = '.';

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        deque<TreeNode*> deq;
        deq.push_back(root);
        
        ostringstream oss;
        
        while (deq.size()) {
            TreeNode* node = deq.front();
            if (node) {
                deq.push_back(node->left);
                deq.push_back(node->right);
                oss << node->val;                
            } else {
                oss << NULL_CHAR;                
            }
            oss << DELIMITER;            
                            
            deq.pop_front();
        }        
        return oss.str();
    }
  
    inline TreeNode* readNode(istringstream& iss) {
        TreeNode* node;
        
        if (iss.eof()) return nullptr;
        
        char c = iss.peek();                
        if (c == NULL_CHAR) {           
            iss >> c;
            node = nullptr;    
        } else if ((c <= '9' && c >= '0') || c == '-') {
            int val;
            iss >> val;
            node = new TreeNode(val);            
        }   
        
        iss >> c; // read the delimiter
        return node;
    }
    
    TreeNode* deserialize(string data) {
        // 1,2,3,..4,5,....
        istringstream iss(data);
       
        deque<TreeNode*> deq;
        
        TreeNode* root = readNode(iss);
        deq.push_back(root);
        
        while(deq.size()) {
            TreeNode* node = deq.front();
            if (node) {
                // read its left and right
                node->left = readNode(iss);
                node->right = readNode(iss);
                if (node->left) deq.push_back(node->left);
                if (node->right) deq.push_back(node->right);
            }            
            deq.pop_front();
        }
        
        return root;
    }
};

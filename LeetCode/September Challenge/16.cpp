class Solution {
public:
	class Node{
	public:
		Node *left, *right;
		bool isEnd;
		Node(){
			left = right = NULL;
		}
	};
	class trie{
	public:
		Node *root;
		int maxAns;
		trie(){
			root = new Node();
			maxAns = 0;
		}
		void insert(int val){
			Node *temp = root;
			for(int i=30; i>=0; i--){
				bool bit = ((val>>i)&1);
				if(bit){
					if(temp->right==NULL){temp->right = new Node();}
					temp = temp->right;
				}
				else{
					if(temp->left==NULL){temp->left = new Node();}
					temp = temp->left;
				}
			}
			xor_helper(val);
		}
		void xor_helper(int val){
			int ans = 0;
			Node *temp = root;
			for(int i=30; i>=0; i--){
				bool bit = ((val>>i)&1);
				if(bit){
					if(temp->left){ans += (1<<i); temp=temp->left;}
					else{temp = temp->right;}
				}
				else{
					if(temp->right){ans += (1<<i); temp=temp->right;}
					else{temp = temp->left;}
				}
			}
			maxAns = max(maxAns, ans);
		}

	};
    int findMaximumXOR(vector<int>& nums) {
        trie root;
        for(auto x:nums){
        	root.insert(x);
        }
        return root.maxAns;
    }
};
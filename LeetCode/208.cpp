class Node{
public:
    map<char, Node*> m;
    bool isEnd;
    Node(){isEnd=0;}
};
class Trie {
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp = root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                temp->m[ch] = new Node();
            }
            temp = temp->m[ch];
        }
        temp->isEnd=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for(auto ch:word){
            if(temp->m.count(ch)==0){return 0;}
            temp = temp->m[ch];
        }
        return temp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = root;
        for(auto ch:prefix){
            if(temp->m.count(ch)==0){return 0;}
            temp = temp->m[ch];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
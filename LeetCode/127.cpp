class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> hash;
        for (int i = 0; i < wordList.size(); i ++)
            hash[wordList[i]] ++;
        if (!hash[endWord]) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int step = 0;
        int len = beginWord.size();
        while (q.size()){
            int sz = q.size();
            step ++;
            for(int k = 0; k < sz; k ++){
                string t = q.front();
                q.pop();
                for (int i = 0; i < len; i ++){
                    for (char c = 'a'; c <= 'z'; c ++){
                        char old = t[i];
                        t[i] = c;
                        if (hash[t]){
                            if (t == endWord) return step + 1;
                            q.push(t);
                            hash[t] --;
                        }
                        t[i] = old;
                    }
                }
            }
        }
        return 0;
    }
};
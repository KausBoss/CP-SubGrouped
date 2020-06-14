class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        for(auto x:p){
        	freqP[x - 'a']++;
        }
        vector<int> ans;
        for(int i=0; i<s.length(); i++){
        	freqS[s[i] - 'a']++;
        	if(freqP == freqS){
        		ans.push_back(i - p.length() +1);
        	}
        	int id = i - p.length() +1;
        	if(id >= 0){
        		freqS[s[id] - 'a']--;
        	} 
        }
        return ans;
    }
};
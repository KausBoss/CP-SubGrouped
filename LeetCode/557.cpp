class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0;
        for(j=0; j<s.length(); j++){
        	if(s[j] == ' '){
        		int k = j-1;
        		while(i < k){
        			swap(s[i++], s[k--]);
        		}
        		i = j+1;
        	}
        }
        int k = s.length() - 1;
        while(i < k){
        	swap(s[i++], s[k--]);
        }
        return s;
    }
};
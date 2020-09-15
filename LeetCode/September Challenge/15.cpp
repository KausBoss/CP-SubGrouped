class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.length() && s.back() == ' '){
        	s.pop_back();
        }
        int n = s.length();
        for(int i=n-1; i>=0; i--){
        	if(s[i] == ' '){
        		return n-1 - i;
        	}
        }
        return n;
    }
};
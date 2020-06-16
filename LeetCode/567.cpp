class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	int len1 = s1.length(), len2 = s2.length();
    	vector<int> freq1(26, 0), freq2(26, 0);
        for(auto x:s1){
        	freq1[x - 'a']++;
        }

        for(int i = 0; i < len2; i++){
        	freq2[s2[i] - 'a']++;
        	if(freq1 == freq2){
        		return true;
        	}
        	if((i + 1 - len1) >= 0){
        		freq2[s2[i + 1 - len1] - 'a']--;
        	}
        }
        return false;
    }
};
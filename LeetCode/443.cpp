class Solution {
public:
    int compress(vector<char>& chars) {
    	int i=0, freq=0;
    	char ch = chars[0];
    	for(int j=0; j<chars.size(); j++){
    		if(chars[j] == ch){
    			freq++;
    		}
    		else{
                chars[i] = ch;
    			string cnt = to_string(freq);
    			i++;
    			if(freq > 1){
	    			for(int k=0; k<cnt.length(); k++){
	    				chars[i++] = cnt[k];
	    			}
    			}
    			freq=1;
	    		ch = chars[j];
    		}
        }
        chars[i] = ch;
        string cnt = to_string(freq);
        i++;
        if(freq > 1){
            for(int k=0; k<cnt.length(); k++){
                chars[i++] = cnt[k];
            }
        }
    	chars.resize(i);
    	return chars.size();
    }
};
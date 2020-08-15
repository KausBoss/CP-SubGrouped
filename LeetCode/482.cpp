class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n= S.length();
        string ans="";
        for(auto x: S){
        	if(x != '-'){
        		if(isalpha(x)){
        			ans += toupper(x);
        		}
        		else{
        			ans += x;
        		}
        	}
        }
        string final ="";
        if(ans.length() == 0){
            return final;
        }
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.length(); i++){
        	final += ans[i];
        	if((i+1)%K == 0){
        		final += '-';
        	}
        }
        if(final.back() == '-'){
            final.pop_back();
        }
        reverse(final.begin(), final.end());
        return final;
    }
}; 
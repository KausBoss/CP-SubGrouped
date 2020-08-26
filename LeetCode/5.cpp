class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length();
        int ans = 0, st;
        if(n == 0){return 0;}
        for(int k=0; k<n; k++){
        	int i=k-1, j=k+1, len=1;
        	while(i>=0 && j<n && s[i]==s[j]){
        		len+=2;
        		i--;j++;
        	}
        	if(ans < len){
        		st=i+1;
        		ans = len;
        	}
        	i=k-1, j=k, len=0;
        	while(i>=0 && j<n && s[i]==s[j]){
        		len+=2;
        		i--;j++;
        	}
        	if(ans < len){
        		st=i+1;
        		ans = len;
        	}
        }
        return s.substr(st, ans);
    }
};
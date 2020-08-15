class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();                 
        int bulls=0, cows=0;
        for(int i=0; i<n; i++){
        	if(secret[i] == guess[i]){
        		bulls++;
        		secret[i] = 'B';
                guess[i] = 'B';
        	}
        }
        int freq[10] = {0};
        for(int i=0; i<n; i++){
        	if(secret[i] >= '0' && secret[i] <= '9'){
        		freq[secret[i] - '0']++;
        	}
        }
        for(int i=0; i<n; i++){
        	if(guess[i] != 'B'){
	        	int digit = guess[i] - '0';
	        	if(freq[digit] > 0){
	        		cows++;
	        		freq[digit]--;
	        	}
        	}
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
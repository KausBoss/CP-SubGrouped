class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int freq[2]={0};
        for(auto x:bills){
        	if(x == 5){
        		freq[0]++;
        	}
        	else if(x == 10){
        		if(freq[0] == 0){
        			return false;
        		}
        		freq[1]++;
                freq[0]--;
        	}
        	else{
        		if(freq[0] == 0){
        			return false;
        		}
        		if(freq[1] > 0){
        			freq[1]--;
        		}
        		else if(freq[0] >= 3){
        			freq[0] -= 2;
        		}
        		else{
        			return false;
        		}
        		freq[0]--;
        	}
        }
        return true;
    }
};
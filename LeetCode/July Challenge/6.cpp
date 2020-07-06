class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0;
        reverse(digits.begin(), digits.end());
        for(int i=0; i<n; i++){
        	if(i == 0){
        		if(digits[i] + 1 > 9){
        			carry++;
        		}
        		digits[i] = (digits[i]+1)%10;
        	}
        	else{
        		int val = digits[i]+carry;
        		carry = (digits[i]+carry)/10;
        		digits[i] = val%10;
        	}
        }
        if(carry){digits.push_back(1);}
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
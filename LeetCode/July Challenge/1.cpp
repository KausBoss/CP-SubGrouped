class Solution {
public:
    int arrangeCoins(int n) {
    	int i;
    	for(i=0; i<INT_MAX; i++){
    		if(i*(i+1)/2 > n){break;}
    	}
    	return i-1;
    }
};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x=0;
        int pos=0;
        while(n > 0){
        	if(n&1){
        		x |=(1<<(31-pos));
        	}
        	pos++;
        	n = n>>1;
        }
        return x;
    }
};
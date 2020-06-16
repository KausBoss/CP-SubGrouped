class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() <= 1){ return false;}
        if(A[0] > A[1]){ return false;}
        bool dec = false;
        

        for(int i=1; i<A.size(); i++){
        	if(A[i] == A[i-1]){ return false;}
        	else if(A[i] < A[i-1]){
        		if(dec == false){
        			dec = true;
        		}
        	}
        	else{
        		if(dec){
        			return false;
        		}
        	}

        }
        return dec == true;
    }
};
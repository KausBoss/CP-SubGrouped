class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0, j=A.size()-1;
        while(i < j){
        	while(i < j && !(A[i]&1)){
        		i++;
        	}
        	while(j > i && (A[j]&1)){
        		j--;
        	}
        	if((A[i]&1) && !(A[j]&1)){
        		swap(A[i], A[j]);
        	}
        }
        return A;
    }
};
class Solution {
public:
	string ret = "";
	int hr=-1, min=0;
	void func(int i, vector<int> A){
		//base case
		if(i == 4){
			int hr1 = A[0]*10 + A[1];
			int min1 = A[2]*10 + A[3];
			if(hr1 >= 24 || min1 >= 60){return;}
			if(hr1 > hr || (hr1==hr && min1 > min)){
				ret = to_string(hr1) + ":" + to_string(min1);
                hr = hr1; min = min1;
				if(hr1 < 10){ret = "0" + ret;}
				if(min1 < 10){
                    char ch = ret.back();
                    ret.pop_back();
                    ret += "0"; ret += ch;}
			}
			return;
		}
		for(int j=i; j<4; j++){
			swap(A[i], A[j]);
			func(i+1, A);
			swap(A[i], A[j]);
		}
		return;
	}
    string largestTimeFromDigits(vector<int>& A) {
    	func(0, A);
    	return ret;
    }
};
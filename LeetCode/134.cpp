class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	//TotalFuel stores the effective fuel left after journey
    	//if neg means, we dont have enough gas to cover the distance
        int TotalFuel = 0, CurrentFuel = 0, id = 0;
        for(int i = 0; i < gas.size(); i++){
        	gas[i] -= cost[i]; //effective fuel that will remain in tank
        	TotalFuel += gas[i];
        	CurrentFuel += gas[i];

        	//if it is impossible to reach here for i = 0, best possibility to reach hear
        	//would be from i, because that will give us max fuel value in tank possible
        	//before reaching i
        	if(CurrentFuel < 0){
        		id = i + 1;
        		CurrentFuel = 0;
        	}
        }

        return TotalFuel < 0 ? -1 : id;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int G = accumulate(gas.begin(), gas.end(),0);
        int C = accumulate(cost.begin(),cost.end(),0);

        if(C>G) return -1; 
        int start=0, RemGas=0; 
        for(int i=0;i<gas.size();i++){
            if(RemGas<0){
                RemGas=0;
                start=i;
            }
            RemGas += gas[i]-cost[i];
        }
        return start;
    }
};
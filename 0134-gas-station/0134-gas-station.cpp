class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasTo = accumulate(gas.begin(),gas.end(),0);
        int costTo = accumulate(cost.begin(),cost.end(),0);
        if(gasTo<costTo) return -1;

        int start = 0;
        int remGas = 0;

        for(int i=0;i<gas.size();i++){
            if (remGas<0){
                start = i;
                remGas = 0;
            }
            remGas += gas[i]-cost[i];
        }
        return start;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int TG = 0,TC = 0; // total cost < total Gas
        int tanki = 0;
        int stIdx = 0;

        for(int i=0;i<gas.size();i++){
            TG += gas[i];
            TC += cost[i];

            tanki += gas[i]-cost[i]; // remaining gas in tanki

            if(tanki<0){
                stIdx=i+1;
                tanki=0;
            }
        }
        return (TG<TC) ? -1 : stIdx;
    }
};
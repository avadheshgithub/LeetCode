class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        int maxFreq = -1;

        for(auto x:tasks){
            freq[x-'A']++;
            maxFreq = max(freq[x-'A'],maxFreq);
        }

        int countMaxFreq = 0;
        for(auto x:freq){
            if(x==maxFreq) countMaxFreq++;
        }

        return max(((maxFreq-1)*(n+1) + countMaxFreq),(int)tasks.size());
    }
};

// (n+1) interval needed per cycle 
// cycle --> maxFreq Char 
// if more than one maxFreq then add them
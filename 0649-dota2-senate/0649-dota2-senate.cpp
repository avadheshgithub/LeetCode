class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int>R,D;

        for(int i=0;i<n;i++){
            if(senate[i]=='R') R.push(i);
            if(senate[i]=='D') D.push(i);
        }

        while(!R.empty() && !D.empty()){
            int Ri = R.front();
            int Di = D.front();
            if(Ri<Di){
                R.push(Ri+n);
            }
            else {
                D.push(Di+n);
            }
            R.pop();
            D.pop();
        }
        return R.empty()? "Dire" : "Radiant";
    }
};
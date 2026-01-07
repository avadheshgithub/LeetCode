class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26);
        for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i; // store last idx of each char
        }

        vector<int>ans;
        int Pend = 0; //P->partition
        int Pst = 0;
        for(int i=0;i<s.length();i++){
            Pend = max(Pend,last[s[i]-'a']);
            if(i==Pend){
                ans.push_back(Pend-Pst+1);
                Pst = i+1;
            }
        }
        return ans;
    }
};
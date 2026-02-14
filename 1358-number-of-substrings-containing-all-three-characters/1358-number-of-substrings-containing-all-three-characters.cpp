class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int>freq(3,0);
        int j = 0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                ans += s.length()-i;
                freq[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string>str(nums.size());
        for(int i=0;i<nums.size();i++){
            str[i]=to_string(nums[i]);
        }
        sort(str.begin(), str.end(), [](const string& a, const string& b) {
            return (a + b) > (b + a);
        });

        if(str[0]=="0") return "0";
        
        string ans;
        for (const string& s : str) {
            ans += s;
        }
        return ans;
    }
};
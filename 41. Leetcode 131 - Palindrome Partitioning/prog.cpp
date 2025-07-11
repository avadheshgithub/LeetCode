// Leetcode 141 - Palindrome Partitioning

// time complexity: O(2^n * n) where n is the length of the string
// space complexity: O(n)


class Solution {
public:
    bool isPalindrom(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getAllParts(string s, vector<string>& partitions,vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);
            
            if(isPalindrom(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i+1),partitions,ans);
                partitions.pop_back(); // backTrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partitions;
        getAllParts(s,partitions,ans);
        return ans;
    }
};
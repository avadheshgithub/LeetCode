// Assign Cookies
// LeetCode Problem 455: Assign Cookies


// Time complexity: O(n log n)
// Space complexity: O(1)   


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end()); // [1 2]
        sort(s.begin(),s.end());//  [1 2 3]
        
        int count=0;
        int i=0;
        int j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                count++;
                i++;j++;
            }
            else j++;
        }
        return count;
    }
};
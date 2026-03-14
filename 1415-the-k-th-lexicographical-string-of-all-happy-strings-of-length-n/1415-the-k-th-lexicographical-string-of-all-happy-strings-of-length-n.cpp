class Solution {
public:
    string ans = "";
    int count = 0;

    void backtrack(string &curr, int n, int k){
        if(curr.size() == n){
            count++;
            if(count == k){
                ans = curr;
            }
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() == c){
                curr.push_back(c);
                backtrack(curr, n, k);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        backtrack(curr, n, k);
        return ans;
    }
};

class Solution {
public:
    vector<int> findMissingElements(vector<int>& arr) {
        vector<int>ans;
        int min = *min_element(arr.begin(),arr.end());
        int max = *max_element(arr.begin(),arr.end());

        unordered_set<int>st;
        for(auto x:arr) st.insert(x);
        
        int i = min;
        while(i<max){
            if(st.find(i)==st.end()) ans.push_back(i);
            i++;
        }
        return ans;
    }
};
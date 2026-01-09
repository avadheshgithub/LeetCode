class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g)); 
        sort(begin(s),end(s));
        
        int count=0,i=0,j=0;

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
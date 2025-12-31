class Solution {
public:
    struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;//max heap

        for(auto point:points){
            pq.push(point);
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;

    }
};
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int>pre(n+1,0);
        vector<int>suf(n+1,0);

        // prefix Sum for N
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1]+ (customers[i-1]=='N' ? 1:0);
        }

        // suffix Sum for Y
        for(int i=n-1;i>=0;i--){
            suf[i] = suf[i+1]+ (customers[i]=='Y' ? 1:0);
        }

        // calculate Min penality and best Hour
        int minPen = INT_MAX;
        int bestHour=0;
        for(int i=0;i<=n;i++){
            int Pen = pre[i] + suf[i];
            if(Pen <minPen){
                minPen = Pen;
                bestHour = i;
            }
        }
        return bestHour;
    }
};
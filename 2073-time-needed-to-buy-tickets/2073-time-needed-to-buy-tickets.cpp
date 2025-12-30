class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;      
        int time = 0;
        
        for (int i=0;i<tickets.size();i++)
            q.push(i);
            
        while (true) {
            int person = q.front();
            q.pop();
            
            time++;                 
            tickets[person]--;
            
            if (tickets[person]>0) q.push(person);  // push back
            else if (person == k) return time;     // target finished
        }
        return -1;  
    }
};
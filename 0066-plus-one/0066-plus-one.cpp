class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {

        for(int i=dig.size()-1;i>=0;i--){
            if(dig[i]!=9){
                dig[i]++;
                return dig;
            }
            dig[i]=0;
        }
        dig.insert(dig.begin(),1);

        return dig;
    }
};
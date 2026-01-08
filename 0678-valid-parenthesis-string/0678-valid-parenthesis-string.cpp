class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for(char c:s){
            if(c=='('){
                minOpen++;
                maxOpen++;
            }
            else if (c==')'){
                minOpen--;
                maxOpen--;
            }
            else{
                minOpen--; // *-> as close
                maxOpen++; // *-> as open
            }
            if(maxOpen<0) return false;
            minOpen = max(minOpen,0); // stop from being negative minOpen
        }
        return minOpen==0;
    }
};
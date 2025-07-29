// count and Say
// Leetcode - 38


// Methode 01 - Recusive
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);

        // str = 3322251 ---> 23 32 15 11 (freq & char)
        string ztr = "";
        int freq=1;
        char ch = str[0];
        for(int i=1;i<str.length();i++){
            char dh = str[i];
            if(ch==dh){
                freq++;
            }
            else{ // ch!=dh
                ztr+=(to_string(freq)+ch); // freq and char
                freq=1;
                ch = dh;
            }
        }
        ztr+=(to_string(freq)+ch); // for last 11 after loop
        return ztr;
    }
};



// Methode 02 - Iterative
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string result = "";
        int count = 1;
        
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                count++;
            } else {
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
        }
        
        result += to_string(count) + prev.back();
        return result;
    }
};


// methide 02 - iterative
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string next = "";
            int count = 1;
            
            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    next += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            
            next += to_string(count) + result.back();
            result = next;
        }
        
        return result;
    }
};
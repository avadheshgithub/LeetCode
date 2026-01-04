class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>arr;

    RandomizedSet() {} // constructor
    
    bool insert(int x) {
        if(mp.count(x)) return false; // already there

        mp[x] = arr.size();
        arr.push_back(x);

        return true;
    }
    
    bool remove(int x) {
        if(mp.count(x)==0) return false; // do not exiest

        int idx = mp[x];
        int lastVal = arr.back();

        arr[idx] = lastVal; // swap
        mp[lastVal] = idx;

        arr.pop_back();
        mp.erase(x);

        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& speed) {
      int n = speed.size();
      vector<vector<double>>cars; //(pos,time)

      for(int i=0;i<n;i++){
        cars.push_back({(double)pos[i], (double)(tar-pos[i])/speed[i]});
      }  
      sort(cars.rbegin(),cars.rend()); //descending

      int fleet = 0;
      double prevTime = 0;
      for(auto &car:cars){
        if(car[1]>prevTime){
            fleet++;
            prevTime = car[1];
        }
      }
      return fleet;
    }
};
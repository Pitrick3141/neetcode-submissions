class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = 0;
        double maxt = -1;
        map<int, int> posSpeed;
        for(int i = 0; i < position.size(); i++) posSpeed[position[i]] = speed[i];
        sort(position.begin(), position.end());
        for(int i = position.size() - 1; i >= 0; i--) {
            double t = (target - position[i]) * 1.0 / posSpeed[position[i]];
            if(t > maxt) {
                fleets ++;
                maxt = t;
            }
        }
        return fleets;
    }
};

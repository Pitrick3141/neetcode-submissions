class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int  l = 0, r = 1;
        while(numbers[r] < target - numbers[l] && r < numbers.size() - 1) r++;
        while(l < r) {
            if(numbers[r] + numbers[l] == target) {
                return {l + 1, r + 1};
            }
            else if (numbers[r] + numbers[l] < target) l ++;
            else r --;
        }
        return {-1, -1};
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix, suffix, prod;
        int cpf = 1, csf = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            cpf *= nums[i];
            csf *= nums[nums.size() - i - 1];
            prefix.push_back(cpf);
            suffix.push_back(csf);
        }
        prod.push_back(suffix[nums.size() - 2]);
        for(int i = 1; i < nums.size() - 1; i++) prod.push_back(prefix[i-1] * suffix[nums.size() - i - 2]);
        prod.push_back(prefix[nums.size() - 2]);
        return prod;
    }
};

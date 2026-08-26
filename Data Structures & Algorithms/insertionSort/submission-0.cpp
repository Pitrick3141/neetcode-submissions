// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ans;
        for(int sorted = 0; sorted < pairs.size(); sorted++) {
            vector<Pair> iter;
            int i = 0, j = sorted;
            while(i < sorted && pairs[i].key <= pairs[j].key) {
                iter.push_back(pairs[i++]);
            }
            iter.push_back(pairs[j++]);
            while(i < sorted) iter.push_back(pairs[i++]);
            while(j < pairs.size()) iter.push_back(pairs[j++]);
            ans.push_back(iter);
            pairs = iter;
        }
        return ans;
    }
};

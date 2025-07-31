class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, next;
        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int x : cur) {
                next.insert(x | num);
            }
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};
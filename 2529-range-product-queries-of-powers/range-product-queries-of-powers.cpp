class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        constexpr int MOD = 1e9 + 7;
        vector<int> bits;
        for (int i = 0; i < 32; ++i){
            if (n & (1 << i)) bits.push_back(i);
        }
        for (int i = 1, sz = bits.size(); i < sz; ++i) bits[i] += bits[i - 1];
        int m = queries.size();
        vector<int> res(m , 0);
        for (int i = 0; i < m; ++i) {
            int start = queries[i][0], end = queries[i][1];
            int shift = bits[end] - (start ? bits[start - 1] : 0);
            long long val = 1;
            while(shift){
                int take = min(shift , 30);
                shift -= take;
                val = (val << take) % MOD;
            }
            res[i] = val;
        }
        return res;
    }
};
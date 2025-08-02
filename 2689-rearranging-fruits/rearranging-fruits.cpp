class Solution {
public:
    using int2=pair<int, int>;
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        const int n=basket1.size();
        unordered_map<int, int> freq;
        freq.reserve(n);

        int minX=INT_MAX;// May swap twice with minX
        for (int i=0; i<n; i++) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
            minX=min(minX, min(basket1[i], basket2[i]));
        }

        vector<int2> B1, B2; // need to swap for backets
        for (auto& [x, f] : freq) {
            if (f%2!=0) return -1;
            if (f>0) B1.emplace_back(x, f/2);
            else if (f<0) B2.emplace_back(x, -f/2);
        }

        sort(B1.begin(), B1.end());
        sort(B2.begin(), B2.end());

        long long cost=0;
        const int m1=B1.size(), m2=B2.size();
        // Greedy here
        for (int i=0, j=m2-1; i<m1 && j>=0;) {
            auto& [b1, f1]=B1[i];
            auto& [b2, f2]=B2[j];
            int f0=min(f1, f2);
            // direct swap or 2 times swaps with minX
            long long swapCost=min(min(b1, b2), 2*minX);
            cost+=swapCost*f0;

            f1-=f0;
            f2-=f0;
            i+=(f1==0);
            j-=(f2==0);
        }

        return cost;
    }
};

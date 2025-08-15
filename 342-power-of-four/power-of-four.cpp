class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<0) return 0;
        bitset<31> x(n);
        if (x.count()!=1) return 0;
        for(int i=0; i<31; i+=2)
            if(x[i]) return 1;
        return 0;
    }
};
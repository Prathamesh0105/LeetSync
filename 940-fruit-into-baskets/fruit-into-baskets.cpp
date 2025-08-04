class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int> mpp;
        int i = 0 , j = 0;
        int ans = 0;
        while(j< fruits.size()){
            mpp[fruits[j]]++;
            while(mpp.size() > 2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
                i++;
            }
            ans = max(ans , j-i+1);
            j++;
        }

        return ans;
    }
};
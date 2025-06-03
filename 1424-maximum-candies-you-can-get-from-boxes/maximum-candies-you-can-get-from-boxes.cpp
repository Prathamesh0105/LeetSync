class Solution {
public:
    int maxCandies(vector<int>& vis, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        bool foundOpenable = true;
        int totalCandies = 0;
        while (!initialBoxes.empty() && foundOpenable) {
            foundOpenable = false;
            vector<int> nextBoxes;
            for (int boxId : initialBoxes) {
                if (vis[boxId]) {
                    foundOpenable = true;
                    nextBoxes.insert(end(nextBoxes), begin(containedBoxes[boxId]), end(containedBoxes[boxId]));
                    for (int keyId : keys[boxId]) vis[keyId] = 1;
                    totalCandies += candies[boxId];
                } else {
                    nextBoxes.push_back(boxId);
                }
            }
            swap(initialBoxes, nextBoxes);
        }
        return totalCandies;
    }
};
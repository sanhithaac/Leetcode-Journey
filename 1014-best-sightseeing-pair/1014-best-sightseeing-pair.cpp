class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = values[0] + 0;  
        int result = 0;

        for (int j = 1; j < values.size(); j++) {
            result = max(result, best + values[j] - j);
            best = max(best, values[j] + j);
        }

        return result;
    }
};
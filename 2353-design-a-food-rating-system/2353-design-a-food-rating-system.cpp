class FoodRatings {
public:
    struct Node {
        int rating;
        string food;
        bool operator<(const Node &other) const {
            if (rating != other.rating) return rating > other.rating;
            return food < other.food;
        }
    };

    unordered_map<string, pair<string,int>> mp;
    unordered_map<string, set<Node>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            mp[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = mp[food].first;
        int oldRating = mp[food].second;

        cuisineMap[cuisine].erase({oldRating, food});
        cuisineMap[cuisine].insert({newRating, food});

        mp[food].second = newRating;
    }

    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->food;
    }
};
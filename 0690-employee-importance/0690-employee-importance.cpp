class Solution {
public:
    unordered_map<int, Employee*> mp;

    int dfs(int id) {
        Employee* emp = mp[id];
        int total = emp->importance;

        for (int sub : emp->subordinates)
            total += dfs(sub);

        return total;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for (auto emp : employees)
            mp[emp->id] = emp;

        return dfs(id);
    }
};
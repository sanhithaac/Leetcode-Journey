class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000"))
            return -1;

        queue<string> q;
        unordered_set<string> vis;

        q.push("0000");
        vis.insert("0000");

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string curr = q.front();
                q.pop();

                if(curr == target)
                    return steps;

                for(int i = 0; i < 4; i++) {
                    string up = curr;
                    string down = curr;

                    // Rotate forward
                    up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;

                    // Rotate backward
                    down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                    if(!dead.count(up) && !vis.count(up)) {
                        vis.insert(up);
                        q.push(up);
                    }

                    if(!dead.count(down) && !vis.count(down)) {
                        vis.insert(down);
                        q.push(down);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> st; // store indices

        for(int i = 0; i < n; i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }

        return ans;
    }
};
class SnapshotArray {
public:
    int snap_id;
    vector<vector<pair<int,int>>> arr;

    SnapshotArray(int length) {
        snap_id = 0;
        arr.resize(length);
        for (int i = 0; i < length; i++)
            arr[i].push_back({0, 0});
    }

    void set(int index, int val) {
        if (arr[index].back().first == snap_id)
            arr[index].back().second = val;
        else
            arr[index].push_back({snap_id, val});
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto &v = arr[index];
        int l = 0, r = v.size() - 1, ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= snap_id) {
                ans = v[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
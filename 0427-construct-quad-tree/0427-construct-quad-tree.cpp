class Solution {
public:
    Node* build(vector<vector<int>>& grid, int r, int c, int n) {
        bool same = true;
        int val = grid[r][c];

        for (int i = r; i < r + n; i++) {
            for (int j = c; j < c + n; j++) {
                if (grid[i][j] != val) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        if (same) return new Node(val, true);

        int half = n / 2;
        Node* root = new Node(1, false);
        root->topLeft = build(grid, r, c, half);
        root->topRight = build(grid, r, c + half, half);
        root->bottomLeft = build(grid, r + half, c, half);
        root->bottomRight = build(grid, r + half, c + half, half);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};
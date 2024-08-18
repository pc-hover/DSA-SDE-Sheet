class NeighborSum {
public:
    vector<vector<int>> grid;

    NeighborSum(vector<vector<int>>& grid1) { grid = grid1; }

    int adjacentSum(int value) {
        int ans = 0;
        int n = grid.size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == value) {
                    int drow[4] = {-1, 0, 1, 0};
                    int dcol[4] = {0, 1, 0, -1};
                    for (int h = 0; h < 4; h++) {
                        if ((i + drow[h]) >= 0 && (j + dcol[h]) >= 0 &&
                            (i + drow[h]) < n && (j + dcol[h]) < n) {
                            ans += grid[i + drow[h]][j + dcol[h]];
                        }
                    }
                }
            }
        }return ans;
        }

        int diagonalSum(int value) {
            int n = grid.size();
            int ans = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {

                    if (grid[i][j] == value) {
                        int drow[4] = {-1, 1, 1, -1};
                        int dcol[4] = {1, 1, -1, -1};
                        for (int h = 0; h < 4; h++) {
                            if ((i + drow[h]) >= 0 && (j + dcol[h]) >= 0 &&
                                (i + drow[h]) < n && (j + dcol[h]) < n) {
                                ans += grid[i + drow[h]][j + dcol[h]];
                            }
                        }
                    }
                }
            }
            return ans;
        }
    };

    /**
     * Your NeighborSum object will be instantiated and called as such:
     * NeighborSum* obj = new NeighborSum(grid);
     * int param_1 = obj->adjacentSum(value);
     * int param_2 = obj->diagonalSum(value);
     */

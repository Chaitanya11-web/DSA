class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j,
             int m, int n, int id, int& cnt) {

        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = id;
        cnt++;

        dfs(grid, i+1, j, m, n, id, cnt);
        dfs(grid, i-1, j, m, n, id, cnt);
        dfs(grid, i, j+1, m, n, id, cnt);
        dfs(grid, i, j-1, m, n, id, cnt);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int,int> map1; // id -> size
        int id = 2;
        int maxCnt = 0;

        /* -------- STEP 1: Label islands -------- */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    dfs(grid, i, j, m, n, id, cnt);
                    map1[id] = cnt;
                    maxCnt = max(maxCnt, cnt);
                    id++;
                }
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        /* -------- STEP 2: Try flipping each 0 -------- */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int size = 1; // flipped cell
                    unordered_set<int> used;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                            grid[ni][nj] > 1 &&
                            used.find(grid[ni][nj]) == used.end()) {

                            size += map1[grid[ni][nj]];
                            used.insert(grid[ni][nj]);
                        }
                    }

                    maxCnt = max(maxCnt, size);
                }
            }
        }

        return maxCnt;
    }
};

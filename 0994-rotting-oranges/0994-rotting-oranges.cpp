class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue < pair < int, int >> q;

        int time = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int x = front.first, y = front.second;
            if (x == -1 && y == -1) {
                time++;
                cout << time << " " << x << " " << y << "\n";
                if(!q.empty()){
                    q.push({-1,-1});
                }
            } else {
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, 1, 0, -1};

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
                
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
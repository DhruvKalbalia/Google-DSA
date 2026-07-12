class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        q.push({row,col});
        grid[row][col] = '0';

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();

            for (int i =0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1'){
                    q.push({nx,ny});
                    grid[nx][ny]='0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();//row
        int n = grid[0].size();//column

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
            }
        }
    }
    return count;
    }
};
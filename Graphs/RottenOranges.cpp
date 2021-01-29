class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i,j;
        int fo=0;
        int mins=0;
        queue<vector<int>> q;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fo++;
            }
        }
        int dir[4][4]={{0,1},{0,-1},{1,0},{-1,0}};
        while(fo && !q.empty()) {
            int nq=q.size();
            mins++;
            for(i=0;i<nq;i++) {
                int x=q.front()[0];
                int y=q.front()[1];
                q.pop();
                for(j=0;j<4;j++) {
                    int nx=x+dir[j][0];
                    int ny=y+dir[j][1];
                    if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]==2||grid[nx][ny]==0)
                        continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                    fo--;
                }
            }
        }
        return fo==0?mins:-1;
    }
};
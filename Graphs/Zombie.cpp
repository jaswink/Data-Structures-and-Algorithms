// question source:
// https://leetcode.com/discuss/interview-question/411357/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minHours (int n, int m, vector<vector<int>>& grid) {
    int i,j;
    int humans=0;
    queue<vector<int>> q;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(grid[i][j]==1)
                q.push({i,j});
            else
                humans++;
        }
    }
    int dir[4][4]={{0,-1},{0,1},{1,0},{-1,0}};
    int hours=0;
    while(humans && !q.empty()) {
        hours++;
        int qsize=q.size();
        for(i=0;i<qsize;i++) {
            int x=q.front()[0];
            int y=q.front()[1];
            q.pop();
            for(j=0;j<4;j++) {
                int newx=x+dir[j][0];
                int newy=y+dir[j][1];
                if(newx<0||newy<0||newx>=n||newy>=m||grid[newx][newy]==1)
                    continue;
                grid[newx][newy]=1;
                q.push({newx,newy});
                humans--;
            }
        }
    }
    return humans==0?hours:-1;
}
int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
    };
    int row = grid.size(), col = grid[0].size();
    cout << minHours(row, col, grid) << endl;
    
    return 0;
}
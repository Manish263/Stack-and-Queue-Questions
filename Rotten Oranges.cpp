You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
  
  ANS: 
      int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i,j;
        //{{r,c},t} queue looks like this 
        queue<pair<pair<int,int>,int>>q;
        //make a visited vector
        int vis[n][m];
    //traverse accross grid and get all oranges that are rottened
        for (i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else {
                    vis[i][j]=0;
                }
            }
        }
//Writing BFS to get to every possible fresh orange.
        int tm=0;
//drow & dcol are used because these are the max possible moves a orange can make (up,down,left,right)
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty()){
//we get r , c , t using q.front()...
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t); //keep max time used.
            q.pop();
            for(i=0;i<4;i++){
                int nrow=r+drow[i]; //neigbhrouing position of each row and col 
                int ncol=c+dcol[i];
//make sure all checks are correct and also check that oranges are not previously rottened and are you a fresh guy.
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m)
                && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1}); // if not previusly rottened make them rottened. and increment timer.
                    vis[nrow][ncol]=2; //marking we've visited that element.
                }
            }
        }
    //check if any oranges are left to be rottened if yes return -1 else return timer.
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        } 
        return tm;
    }

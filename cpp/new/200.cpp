// Time:  O(n)
// Space: O(1)
#include<string>
#include<iostream>
#include<algorithm>

class Solution {
public:
  
    using matrix = vector<vector<int>>;
    int num_row, num_col;      
        
    int numDistinctIslands(matrix& grid) {
        num_row = grid.size();
        num_col = grid[0].size();
        int num_isl = 0;
        
        for(int i=0;i<num_row;++i)
          for(int j=0;j<num_col;++j){
            if(grid[i][j]){
              ++num_isl;
              dfs(i,j,grid);
            }
          }
    }
    
    void dfs(int i,int j, matrix& grid){
      if(!grid(i, j))
        return;
      if(i>0)
        dfs(i-1, j, grid);
      if(i<num_row-1)
        dfs(i+1, j, grid);
      if(j>0)
        dfs(i, j-1, grid);
      if(i<num_col-1)
        dfs(i, j+1, grid);      
    }
};

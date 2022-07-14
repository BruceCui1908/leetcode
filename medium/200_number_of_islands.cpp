#include <vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    int height = grid.size();
    if (!height) {
      return 0;
    }

    int width = grid[0].size();

    int num = 0;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (grid[i][j] == '1') {
          num++;
          dfs(grid, i, j);
        }
      }
    }

    return num;
  }

  void dfs(std::vector<std::vector<char>> &grid, int h, int w) {
    int height = grid.size();
    int width = grid[0].size();
    grid[h][w] = '0';

    if (h - 1 >= 0 && grid[h - 1][w] == '1') {
      dfs(grid, h - 1, w);
    }

    if (h + 1 < height && grid[h + 1][w] == '1') {
      dfs(grid, h + 1, w);
    }

    if (w - 1 >= 0 && grid[h][w - 1] == '1') {
      dfs(grid, h, w - 1);
    }

    if (w + 1 < width && grid[h][w + 1] == '1') {
      dfs(grid, h, w + 1);
    }
  }
};
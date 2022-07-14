#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int height = board.size();
    int width = board[0].size();
    vector<vector<bool>> visited(height, vector<bool>(width));

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        bool flag = check(board, visited, i, j, word, 0);
        if (flag) {
          return true;
        }
      }
    }

    return false;
  }

  bool check(vector<vector<char>> &board, vector<vector<bool>> &visited, int i,
             int j, string &word, int index) {

    if (board[i][j] != word[index]) {
      return false;
    } else if (index == word.length() - 1) {
      return true;
    }

    visited[i][j] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool result = false;

    for (const auto &dir : directions) {
      int new_di = i + dir.first;
      int new_dj = j + dir.second;
      if (new_di >= 0 && new_di < board.size() && new_dj >= 0 &&
          new_dj < board[0].size()) {
        // 剪枝
        if (!visited[new_di][new_dj]) {
          bool flag = check(board, visited, new_di, new_dj, word, index + 1);
          if (flag) {
            result = true;
            break;
          }
        }
      }
    }

    visited[i][j] = false;
    return result;
  }
};
//
// Created by AILEE on 2023/2/19.
// 题目12：矩阵中的路径
// 题目：给定一个m*n的二维字符网络board和一个字符串单词word。如果word存在于网络中，返回true，否则返回false。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkExistStatus(vector<vector<char>> &board, const string &word, int i, int j, int k, vector<vector<bool>> &visited) {
    // 当前位置的字符与词中k位置的字符不匹配
    if (board[i][j] != word[k]) {
        return false;
    }

    // 匹配到词尾了
    if (k == word.length() - 1) {
        return true;
    }

    // 将当前字符标记为已访问
    visited[i][j] = true;
    bool result = false;
    vector<pair<int, int>> poseDict = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto &dict : poseDict) {
        int ii = i + dict.first;
        int jj = j + dict.second;
        // 保证遍历字符在board范围内
        if (ii >= 0 && ii < board.size() && jj >= 0 && jj < board[0].size()) {
            // 如果当前坐标位置未被访问
            if (!visited[ii][jj]) {
                bool flag = checkExistStatus(board, word, ii, jj, k + 1, visited);
                // 找到了匹配的前进方向
                if (flag) {
                    result = flag;
                    break;
                }
            }
        }
    }

    // 返回上一节点，取消已访问标记
    visited[i][j] = false;
    return result;
}

bool PathInMatrix(vector<vector<char>> &board, const string &word) {
    // 获取board的宽高
    int h = board.size();
    int w = board[0].size();
    // 创建访问矩阵
    vector<vector<bool>> visited(h, vector<bool>(w));
    // 从board的左上角开始遍历，直到找到合适的路径
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            bool  flag = checkExistStatus(board, word, i, j, 0, visited);
            if (flag) {
                return flag;
            }
        }
    }

    return false;
}

void test(const char* testName, vector<vector<char>> &board, const string &word) {
    cout << testName << endl;

    cout << PathInMatrix(board, word) << endl;
}

void test_01() {
    vector<vector<char>> board = {{'a','a','b','a','a','b'},
                                  {'b','a','b','a','b','b'},
                                  {'b','a','b','b','b','b'},
                                  {'a','a','b','a','b','a'},
                                  {'b','b','a','a','a','b'},
                                  {'b','b','b','a','b','a'}};

    test("test 01", board, "aaaababab");
    test("test 02", board, "abcdef");
    test("test 03", board, "gcedfb");
}

int main(int argc, char** argv) {
    test_01();

    return 0;
}

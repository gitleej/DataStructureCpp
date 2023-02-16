//
// Created by AILEE on 2023/2/16.
// 题目19：正则表达式匹配
// 题目：请实现一个函数来匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包括0次），在本题中，
// 匹配是指字符串的所有字符匹配整个模式，例如：字符串“aaa”与模式“a.a”和“ab*ac*a”匹配，但与“aa.a”和“ab*a”不匹配。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 动态规划
 *
 * @param s 待匹配字符串
 * @param p 匹配模式
 * @return 匹配结果
 */
bool isMatch(string s, string p) {
    int m = s.size() + 1, n = p.size() + 1;
    vector<vector<bool>> dp(m, vector<bool>(n, false));
    // s前0个字符和p的前0个字符默认是空串=匹配
    // 注意：由于多了[0][0],所以dp[i][j],定位到的是s[i-1]和p[j-1]的字符
    dp[0][0] = true;
    // 初始化首行:当s为空串,p的偶数位为*才能匹配
    for(int j = 2; j < n; j += 2)
        dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
    // 状态转移
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            // 当p[j-1]=*时,有三种情况
            if(p[j - 1] == '*') {
                if(dp[i][j - 2]) {
                    dp[i][j] = true;                                // 1.p[j-2]出现0次,i和j指向字符的长度均相同
                }
                else if(dp[i - 1][j] && s[i - 1] == p[j - 2]) {
                    dp[i][j] = true;                                // 2.p[j-2]出现1次 且 当前i-1和j-2指向的字符相同
                }
                else if(dp[i - 1][j] && p[j - 2] == '.') {
                    dp[i][j] = true;                                // 3.最特殊情况:p[j-2]=. p[j-1]=*时 是万能匹配
                }
            } else { // 当p[j-1]!=*时,有两种情况
                if(dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) {
                    dp[i][j] = true;                                // 1.前面元素之前都匹配 且 当前元素也相同
                }
                else if(dp[i - 1][j - 1] && p[j - 1] == '.') {
                    dp[i][j] = true;                                // 2.前面元素之前都匹配 且 p的当期元素是.
                }
            }
        }
    }
    return dp[m - 1][n - 1];
}

void test(const char* testName, string &str, string &pattern) {
    cout << testName << endl;

    if (isMatch(str, pattern)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

void test_01() {
    string str = "";
    string pattern = "";

    test("test 01", str, pattern);
}

void test_02() {
    string str = "aa";
    string pattern = "a";

    test("test 02", str, pattern);
}

void test_03() {
    string str = "aa";
    string pattern = "a*";

    test("test 03", str, pattern);
}

void test_04() {
    string str = "ab";
    string pattern = ".*";

    test("test 04", str, pattern);
}

void test_05() {
    string str = "aab";
    string pattern = "c*a*b";

    test("test 05", str, pattern);
}

void test_06() {
    string str = "mississippi";
    string pattern = "mis*is*p*.";

    test("test 06", str, pattern);
}

void test_07() {
    string str = "aab";
    string pattern = "*c*a*b";

    test("test 07", str, pattern);
}

int main(int argc, char ** argv) {
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();

    return 0;
}

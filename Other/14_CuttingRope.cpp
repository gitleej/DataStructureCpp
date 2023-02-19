//
// Created by AILEE on 2023/2/19.
// 題目14：剪绳子
// 题目：给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
// 请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
//

#include <iostream>
#include <vector>

using namespace std;

int CuttingRope(int n) {
    vector<int> dp(n + 1);
    // 因为0和1不可拆分，所以
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    for (int i = 2; i <= n; ++i) {
        int curtMax = 0;
        for (int j = 1; j < i; ++j) {
            curtMax = std::max(curtMax, std::max(j * (i - j), j * dp[i - j]));
        }
        dp[i] = curtMax;
    }

    return dp[n];
}

void test(const char *testName, int n) {
    cout << testName << endl;

    cout << CuttingRope(n) << endl;
}

void test_01() {
    test("test  01", 0);
    test("test  02", 1);
    test("test  03", 2);
    test("test  04", 3);
    test("test  05", 4);
    test("test  06", 5);
    test("test  07", 6);
}

int main(int argc, char **argv) {
    test_01();

    return 0;
}
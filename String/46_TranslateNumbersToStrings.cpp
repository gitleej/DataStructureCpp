//
// Created by AILEE on 2023/2/17.
// 题目46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译成字符串：0翻译成a，1翻译成b，……25翻译成z。一个数字可能有多种翻译结果。
//

#include <iostream>
#include <string>

using namespace std;

int TranslateNumbers2Strings(int number) {
    string numberStr = to_string(number);
    if (numberStr.size() < 2) {
        return numberStr.length();
    }

    int *dp = new int[numberStr.length()];
    dp[0] = 1;
    for (int i = 1; i < numberStr.length(); ++i) {
        int currentNum = (numberStr[i - 1] - '0') * 10 + (numberStr[i] - '0');
        // 当前位和前一位组成的数字在10-25范围内才能被翻译
        if (currentNum > 9 && currentNum < 26) {
            if ((i - 2) < 0) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        } else {
            dp[i] = dp[i - 1];
        }
    }

    int result = dp[numberStr.length() - 1];
    delete [] dp;
    return result;
}

void test(const char* testName, int number) {
    cout << testName << endl;

    cout << TranslateNumbers2Strings(number) << endl;
}

void test_01() {
    test("test 01", 0);
    test("test 02", 102);
    test("test 03", 10203);
    test("test 04", 102030201);
    test("test 05", -102030201);
    test("test 06", -102);
    test("test 07", -10203);
}

int main(int argc, char** argv) {
    test_01();

    return 0;
}
//
// Created by AILEE on 2023/2/18.
// 题目10_02：青蛙跳台阶问题
// 题目：一只请勿一次可以跳上一级台阶，也可以跳上两级台阶，求青蛙跳上n级台阶共有多少种跳法。
//

#include <iostream>

using namespace std;

long long JumpSteps(int n) {
    if (n <= 1) {
        return 1;
    }

    long long fn_1 = 1;
    long long fn_2 = 1;
    long long fn = 0;
    for (int i = 2; i <= n; ++i) {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }

    return fn;
}

void test(const char* testName, int n) {
    cout << testName << endl;

    cout << JumpSteps(n) << endl;
}

void test_01() {
    test("test 01", 0);
    test("test 02", 1);
    test("test 03", 2);
    test("test 04", 5);
    test("test 05", 10);
    test("test 06", 50);
    test("test 07", 100);
}

int main(int argc, char** argv) {
    test_01();

    return 0;
}
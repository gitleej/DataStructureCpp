//
// Created by AILEE on 2023/2/17.
// 题目10_01：斐波那契数列
// 题目：写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
// F(0) = 0,
// F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
//

#include <iostream>

using namespace std;

int FibonacciRecursively(int n) {
    if ( n <= 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return FibonacciRecursively(n - 1) + FibonacciRecursively(n - 2);
}

int FibonacciIteratively(int n) {
    int MOD = 1000000007;
    if (n <= 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    int fi_1 = 1;
    int fi_2 = 0;
    int fi = 0;
    for (int i = 2; i <= n; ++i) {
        fi = (fi_1 + fi_2) % (MOD);
        fi_2 = fi_1;
        fi_1 = fi;
    }

    return fi;
}

void test(const char *testName, int n) {
    cout << testName << endl;

    cout << "Iteratively" << endl;
    cout << FibonacciIteratively(n) << endl;
    cout << "Recursively" << endl;
    cout << FibonacciRecursively(n) << endl;
}

void test_01_05() {
    test("test 01", -1);
    test("test 02", 0);
    test("test 03", 1);
    test("test 04", 10);
    test("test 05", 45);
}

int main(int argc, char** argv) {
    test_01_05();

    return 0;
}
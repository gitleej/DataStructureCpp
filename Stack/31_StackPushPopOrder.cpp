//
// Created by AILEE on 2023/2/17.
// 题目31：栈的压入弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入序列，请判断第二个序列是否为该栈的弹出序列，假设压入栈的所有数字不相等。例如：序列{1，2，3，4，5}
// 是某栈的压入序列，序列{4，5，3，2，1}是该栈序列对应的一个弹出序列，但{4，3，5，1，，2}就不可能是该压栈序列的弹出序列。
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool MatchStackPushPopOrder(vector<int> &pushed, vector<int> &popped) {
    stack<int> temp;
    int i = 0;
    for (auto &it : pushed) {
        temp.push(it);
        while (!temp.empty() && popped[i] == temp.top()) {
            i++;
            temp.pop();
        }
    }
    return temp.empty();
}

void test(const char *testName, vector<int> &pushed, vector<int> &popped) {
    cout << testName << endl;

    cout << MatchStackPushPopOrder(pushed, popped) << endl;
}

void test_01() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};

    test("test 01", pushed, popped);
}

void test_02() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 1, 2};

    test("test 02", pushed, popped);
}

int main(int argc, char** argv) {
    test_01();
    test_02();

    return 0;
}
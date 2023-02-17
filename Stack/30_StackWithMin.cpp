//
// Created by AILEE on 2023/2/17.
// 题目30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
//

#include <iostream>
#include <stack>

using namespace std;

template<class T>
class MinStack {
public:
    MinStack() = default;
    ~MinStack() = default;

    void push(T value);

    void pop();

    T top();

    T min();
private:
    stack<T> rawStack;
    stack<T> minStack;
};

template<class T>
void MinStack<T>::push(T value) {
    rawStack.push(value);
    if (minStack.empty() || minStack.top() >= value) {
        minStack.push(value);
    }
}

template<class T>
void MinStack<T>::pop() {
    if (rawStack.empty()) {
        throw logic_error("MinStack is empty.");
    }
    T value = rawStack.top();
    if (value == minStack.top()) {
        minStack.pop();
    }

    rawStack.pop();
}

template<class T>
T MinStack<T>::top() {
    if (rawStack.empty()) {
        throw logic_error("MinStack is empty.");
    }

    return rawStack.top();
}

template<class T>
T MinStack<T>::min() {
    if (minStack.empty()) {
        throw logic_error("MinStack is empty.");
    }
    return minStack.top();
}

void test_01() {
    MinStack<int> minStack;

    minStack.push(2);
    cout << "min:" << minStack.min() << "\ttop:" << minStack.top() << endl;
    minStack.push(0);
    cout << "min:" << minStack.min() << "\ttop:" << minStack.top() << endl;
    minStack.push(3);
    cout << "min:" << minStack.min() << "\ttop:" << minStack.top() << endl;
    minStack.push(0);
    cout << "min:" << minStack.min() << "\ttop:" << minStack.top() << endl;
    minStack.pop();
    cout << "min:" << minStack.min() << "\ttop:" << minStack.top() << endl;
    minStack.pop();
    cout << "min:" << minStack.min() << "\ttop:" << minStack.top() << endl;
    try {
        minStack.pop();
        cout << "min:" << minStack.min() << "\ttop:" << minStack.top() << endl;
    } catch (logic_error &e) {
        cout << e.what() << endl;
    }

}

int main(int argc, char** argv) {
    test_01();

    return 0;
}

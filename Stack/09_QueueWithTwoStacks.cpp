//
// Created by AILEE on 2023/2/17.
// 题目9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
//

#include <iostream>
#include <stack>

using namespace std;

template<class T>
class CQueue {
public:
    CQueue() = default;;

    ~CQueue() = default;;

    void appendTail(const T &value);

    T deleteHead();

private:
    stack<T> stackIn;
    stack<T> stackOut;
};

template<class T>
void CQueue<T>::appendTail(const T &value) {
    stackIn.push(value);
}

template<class T>
T CQueue<T>::deleteHead() {
    if (stackOut.empty()) {
        if (stackIn.empty()) {
            throw logic_error("Queue is empty.");
        } else {
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
            T value = stackOut.top();
            stackOut.pop();
            return value;
        }
    } else {
        T value = stackOut.top();
        stackOut.pop();
        return value;
    }
}

void test_01() {
    CQueue<char> chCQueue;

    try {
        chCQueue.appendTail('a');
        chCQueue.appendTail('b');
        chCQueue.appendTail('c');
        cout << chCQueue.deleteHead() << " ";
        cout << chCQueue.deleteHead() << " ";
        chCQueue.appendTail('d');
        chCQueue.appendTail('e');
        cout << chCQueue.deleteHead() << " ";
        cout << chCQueue.deleteHead() << " ";
        cout << chCQueue.deleteHead() << " ";
        cout << chCQueue.deleteHead() << " ";
    } catch (logic_error &error) {
        cout << error.what() << endl;
    }
}

int main(int argc, char **argv) {
    test_01();

    return 0;
}

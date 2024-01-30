#include "../../include/common.hpp"

/* 基于链表实现的队列 */

void freeMemoryLinkedList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *next = nullptr;
    while (next != nullptr)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}

template <typename T>
void printVector(vector<T> vec)
{
    for (auto x : vec)
        cout << "'" << to_string(x) << "'"
             << " ";
    cout << "\n";
}

class LinklistStack
{
private:
    ListNode *stackTop; // 将头节点作为栈顶
    int stackSize;      // 栈的长度
public:
    LinklistStack()
    {
        stackTop = nullptr;
        stackSize = 0;
    }
    ~LinklistStack()
    {
        // 释放内存
        freeMemoryLinkedList(stackTop);
    }
    // 栈的大小
    int size()
    {
        return stackSize;
    }
    // 判断栈是否为空

    bool isEmpty()
    {
        return size() == 0;
    }

    // 入栈

    void push(int num)
    {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stackSize++;
    }
    // 出栈
    void pop()
    {
        int num = top();
        ListNode *node = stackTop;
        stackTop = stackTop->next;
        delete node;
        stackSize--;
    }

    // 访问栈顶元素
    int top()
    {
        if (isEmpty())
            throw out_of_range("栈为空");
        return stackTop->val;
    }

    // 将list转化为array，并返回
    vector<int> toVector()
    {
        ListNode *node = stackTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

int main()
{
    /* 初始化栈 */
    LinklistStack *stack = new LinklistStack();

    /* 元素入栈 */
    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    cout << "栈 stack = ";
    printVector(stack->toVector());

    /* 访问栈顶元素 */
    int top = stack->top();
    cout << "栈顶元素 top = " << top << endl;

    /* 元素出栈 */
    stack->pop();
    cout << "出栈元素 pop = " << top << "，出栈后 stack = ";
    printVector(stack->toVector());

    /* 获取栈的长度 */
    int size = stack->size();
    cout << "栈的长度 size = " << size << endl;

    /* 判断是否为空 */
    bool empty = stack->isEmpty();
    cout << "栈是否为空 = " << empty << endl;

    // 释放内存
    delete stack;

    return 0;
}
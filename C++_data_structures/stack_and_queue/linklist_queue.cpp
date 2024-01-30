#include "../../include/common.hpp"

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

class LinklistQueue
{

private:
    ListNode *front, *rear; // 头节点 尾节点
    int queueSize;

public:
    LinklistQueue() : front(nullptr), rear(nullptr), queueSize(0)
    {
    }
    ~LinklistQueue()
    {
        freeMemoryLinkedList(front);
    }
    // 获取队列的长度
    int size()
    {
        return queueSize;
    }
    // 判断队列是否为空
    bool isEmpty()
    {
        return size() == 0;
    }
    // 入队
    void push(int num)
    {
        ListNode *node = new ListNode(num);
        if (front == nullptr)
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
        queueSize++;
    }

    // 出队
    void pop()
    {
        int num = peek();
        if (num == 1)
        {
            ListNode *node = front;
            front = front->next;
            rear = nullptr;
            delete node;
            queueSize--;
        }
        else
        {
            ListNode *node = front;
            front = front->next;
            delete node;
            queueSize--;
        }
    }

    // 访问队首元素
    int peek()
    {
        if (size() == 0)
            throw out_of_range("队列为空");
        return front->val;
    }

    // 将链表转化为 Vector 并返回
    vector<int> toVector()
    {
        ListNode *node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

int main()
{
    /* 初始化队列 */
    LinklistQueue *queue = new LinklistQueue();

    /* 元素入队 */
    queue->push(1);
    queue->push(3);
    queue->push(2);
    queue->push(5);
    queue->push(4);
    cout << "队列 queue = ";
    printVector(queue->toVector());

    /* 访问队首元素 */
    int peek = queue->peek();
    cout << "队首元素 peek = " << peek << endl;

    /* 元素出队 */
    queue->pop();
    cout << "出队元素 pop = " << peek << "，出队后 queue = ";
    printVector(queue->toVector());

    /* 获取队列的长度 */
    int size = queue->size();
    cout << "队列长度 size = " << size << endl;

    /* 判断队列是否为空 */
    bool empty = queue->isEmpty();
    cout << "队列是否为空 = " << empty << endl;

    // 释放内存
    delete queue;

    return 0;
}
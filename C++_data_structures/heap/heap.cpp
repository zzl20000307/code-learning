#include "../../include/common.hpp"

int main()
{
    // 初始化大顶堆、小顶堆
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // 入堆
    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(4);
    // 获取堆顶元素
    int peek = maxHeap.top();
    // 堆顶元素出堆
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    // 获取堆大小
    int size = maxHeap.size();
    // 判断堆是否为空
    bool isEmpty = maxHeap.empty();
    // 输入队列并建立堆
    vector<int> input{1, 3, 2, 5, 4};
    priority_queue<int, vector<int>, greater<int>> minHeapTemp(input.begin(), input.end());
}
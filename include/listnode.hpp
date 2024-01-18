#pragma once

#include <iostream>
#include <vector>

using namespace std;

// 定义链表节点

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};



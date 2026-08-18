#define _CRT_SECURE_NO_WARNINGS 

    // 随机链表的复制
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
    // 方法一（链表实现）
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == nullptr)
//            return nullptr;
//
//        Node* pcur = head;
//
//        while (pcur)
//        {
//            Node* node = new Node(pcur->val);
//            node->next = pcur->next;
//            pcur->next = node;
//            pcur = pcur->next->next;
//        }
//
//        pcur = head;
//        while (pcur)
//        {
//            if (pcur->random)
//                pcur->next->random = pcur->random->next;
//            else
//                pcur->next->random = nullptr;
//            pcur = pcur->next->next;
//        }
//
//        pcur = head;
//        Node* ret = head->next;
//        Node* tmp = ret;
//        while (pcur)
//        {
//            pcur->next = tmp->next;
//            if (pcur->next != nullptr)
//                tmp->next = pcur->next->next;
//            else
//                tmp->next = nullptr;
//            pcur = pcur->next;
//            tmp = tmp->next;
//        }
//
//        return ret;
//    }
//};
    // 方法二（map实现）


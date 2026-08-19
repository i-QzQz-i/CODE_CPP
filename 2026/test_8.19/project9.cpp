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
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == nullptr)
//            return nullptr;
//
//        Node* phead, * ptail, * pcur;
//        phead = ptail = new Node(head->val);
//        pcur = head->next;
//        map<Node*, Node*> mNode;
//        mNode.insert({ head, phead });
//
//        // 新建节点并储存random
//        while (pcur)
//        {
//            ptail->next = new Node(pcur->val);
//            mNode[pcur] = ptail->next;
//            pcur = pcur->next;
//            ptail = ptail->next;
//        }
//
//        pcur = head;
//        ptail = phead;
//        // 链接random
//        while (pcur)
//        {
//            ptail->random = mNode[pcur->random];
//            pcur = pcur->next;
//            ptail = ptail->next;
//        }
//
//        return phead;
//    }
//};


    // 前k个高频单词（暂未通过）
//class Solution {
//public:
//    struct Compare
//    {
//        bool operator()(pair<string, int>& x, pair<string, int>& y) const
//        {
//            return x.second > y.second;
//        }
//    };
//
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> m;
//
//        for (const auto& str : words)
//        {
//            m[str]++;
//        }
//
//        vector<pair<string, int>> v(m.begin(), m.end());
//        sort(v.begin(), v.end(), Compare());
//
//        vector<string> ret;
//        for (int i = 0; i < k; i++)
//        {
//            ret[i] = v[i].first;
//        }
//
//        return ret;
//    }
//};


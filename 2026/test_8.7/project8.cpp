#define _CRT_SECURE_NO_WARNINGS 

	// 环状链表 2（set实现）
	// 方法1（仅set）
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        std::set<ListNode*> tree;
//        ListNode* pcur = head;
//
//        while (pcur)
//        {
//            tree.insert(pcur);
//            pcur = pcur->next;
//
//            if (tree.count(pcur))
//            {
//                return pcur;
//            }
//        }
//
//        return nullptr;
//    }
//};
	// 方法2（借用pair）
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        std::set<ListNode*> tree;
//        ListNode* pcur = head;
//
//        while (pcur)
//        {
//            auto x = tree.insert(pcur);
//
//            if (x.second == false)
//            {
//                return pcur;
//            }
//
//            pcur = pcur->next;
//        }
//
//        return nullptr;
//    }
//};


	// 两个数组的交集
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        set<int> s1(nums1.begin(), nums1.end());
//        set<int> s2(nums2.begin(), nums2.end());
//        vector<int> ret;
//
//        auto p1 = s1.begin();
//        auto p2 = s2.begin();
//
//        while (p1 != s1.end() && p2 != s2.end())
//        {
//            if (*p1 == *p2)
//            {
//                ret.push_back(*p1);
//
//                *p1++;
//                *p2++;
//            }
//            else if (*p1 < *p2)
//            {
//                *p1++;
//            }
//            else
//            {
//                *p2++;
//            }
//        }
//
//        return ret;
//    }
//};

	//如果是并集的情况
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        set<int> s1(nums1.begin(), nums1.end());
//        set<int> s2(nums2.begin(), nums2.end());
//        vector<int> ret;
//
//        auto p1 = s1.begin();
//        auto p2 = s2.begin();
//
//        while (p1 != s1.end() && p2 != s2.end())
//        {
//            if (*p1 == *p2)
//            {
//                *p1++;
//                *p2++;
//            }
//            else if (*p1 < *p2)
//            {
//                ret.push_back(*p1);
//                *p1++;
//            }
//            else
//            {
//                ret.push_back(*p2);
//                *p2++;
//            }
//        }
//
//        if (p1 == s1.end())
//        {
//            while (p2 != s2.end())
//            {
//                ret.push_back(*p2);
//                *p2++;
//            }
//        }
//        else
//        {
//            while (p1 != s1.end())
//            {
//                ret.push_back(*p1);
//                *p1++;
//            }
//        }
//
//        return ret;
//    }
//};
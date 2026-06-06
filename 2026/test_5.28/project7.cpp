#define _CRT_SECURE_NO_WARNINGS 

	// 二叉树的层序遍历
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vv;
//        queue<TreeNode*> qu;
//        int leveSize = 0;
//        if (root)
//        {
//            qu.push(root);
//        }
//
//        while (qu.size() != 0)
//        {
//            leveSize = qu.size();
//            vector<int> v;
//            while (leveSize--)
//            {
//                TreeNode* tmp = qu.front();
//                qu.pop();
//                //vv[count].push_back(tmp->val);
//                v.push_back(tmp->val);
//                if (tmp->left)
//                    qu.push(tmp->left);
//
//                if (tmp->right)
//                    qu.push(tmp->right);
//            }
//
//            vv.push_back(v);
//        }
//
//        return vv;
//    }
//};

	// 字符串相加（大数相加）
	// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int next = 0;
//        string sum;
//        while (!num1.empty() && !num2.empty())
//        {
//            int tmp = num1[num1.size() - 1] - '0' + num2[num2.size() - 1] - '0' + next;
//            next = tmp / 10;
//            tmp %= 10;
//            char x = tmp + '0';
//            sum.push_back(x);
//
//            num1.pop_back();
//            num2.pop_back();
//        }
//
//        while (!num1.empty())
//        {
//            int tmp = num1[num1.size() - 1] - '0' + next;
//            next = tmp / 10;
//            tmp %= 10;
//            char x = tmp + '0';
//            sum.push_back(x);
//
//            num1.pop_back();
//        }
//
//        while (!num2.empty())
//        {
//            int tmp = num2[num2.size() - 1] - '0' + next;
//            next = tmp / 10;
//            tmp %= 10;
//            char x = tmp + '0';
//            sum.push_back(x);
//
//            num2.pop_back();
//        }
//
//        if (next)
//        {
//            char x = next + '0';
//            sum.push_back(x);
//        }
//
//        // 逆置
//        reverse(sum.begin(), sum.end());
//
//        return sum;
//    }
//};
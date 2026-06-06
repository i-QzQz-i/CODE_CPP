#define _CRT_SECURE_NO_WARNINGS 

	// 字符串最后一个单词的长度
	// 方法一（自我实现）（以后默认）
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string arr("");
//    char tmp[1000] = {};
//    while (cin >> tmp)
//    {
//        arr += tmp;
//        arr.push_back(' ');
//    }
//
//    int _size = 0, size = 0;
//
//    for (int i = 0; arr[i] != '\0'; i++)
//    {
//        if (arr[i] == ' ')
//        {
//            size = _size;
//            _size = 0;
//            continue;
//        }
//        _size++;
//    }
//
//    cout << size << endl;
//
//    return 0;
//}
	// 方法二（学习过后）


	// 验证回文串（大写字符转换为小写字符、并移除所有非字母数字字符）
//class Solution {
//public:
//    bool isPalindrome(string s) {
//        string str("");
//        for (int i = 0; i < s.size(); i++)
//        {
//            if ((s[i] >= 'a' && s[i] <= 'z')
//                || (s[i] >= '0' && s[i] <= '9'))
//                str += s[i];
//            else if (s[i] >= 'A' && s[i] <= 'Z')
//                str += s[i] + 32;
//        }
//
//        string::iterator it = str.begin();
//        string::reverse_iterator rit = str.rbegin();
//        for (int i = 0; i < str.size() / 2; i++)
//        {
//            if (*it != *rit)
//                return false;
//
//            ++it;
//            ++rit;
//        }
//
//        return true;
//    }
//};


	// 翻转二叉树（推倒重新实现 8min）
//void invertTree_(struct TreeNode* root)
//{
//    if (root == NULL)
//        return;
//
//    invertTree_(root->left);
//    invertTree_(root->right);
//
//    struct TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//}
//
//struct TreeNode* invertTree(struct TreeNode* root) {
//    invertTree_(root);
//
//    return root;
//}
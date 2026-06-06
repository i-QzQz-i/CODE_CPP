	// 仅仅反转字符
	// 方法一（自己实现的）
//class Solution {
//public:
//    string reverseOnlyLetters(string s) {
//        //cin >> s;
//        int size = 0, rsize = s.size();
//        char tmp = 0;
//        string::iterator it = s.begin();
//        string::reverse_iterator rit = s.rbegin();
//        while (size < rsize)
//        {
//            if ((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z'))
//            {
//                tmp = *it;
//                while (rsize--)
//                {
//                    if ((*rit >= 'a' && *rit <= 'z') || (*rit >= 'A' && *rit <= 'Z'))
//                    {
//                        *it = *rit;
//                        *rit = tmp;
//                        ++rit;
//                        break;
//                    }
//
//                    ++rit;
//                }
//            }
//
//            ++size;
//            ++it;
//        }
//
//        return s;
//    }
//};
	// 方法二（学习过后的）（思路其实一样的）
//class Solution {
//public:
//    bool determine(char x)
//    {
//        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
//            return true;
//        else
//            return false;
//    }
//
//    string reverseOnlyLetters(string s) {
//        int left = 0, right = s.size() - 1;
//
//        while (left < right)
//        {
//            if (left < right && determine(s[left]))
//            {
//                while (right > 0)
//                {
//                    if (determine(s[right]))
//                    {
//                        swap(s[left], s[right--]);
//                        break;
//                    }
//
//                    --right;
//                }
//            }
//
//            ++left;
//        }
//
//        return s;
//    }
//};


	// 字符串中第一个唯一字符
	// 方法一（自己实现的）
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int begin = 0;
//        while (begin < s.size())
//        {
//            char tmp = s[begin];
//            int n = begin + 1;
//            int size = 0;
//            while (n < s.size())
//            {
//                if (tmp == s[n])
//                {
//                    s[n] = 0;
//                    ++size;
//                }
//
//                ++n;
//            }
//
//            if (size == 0)
//            {
//                return begin;
//            }
//
//            ++begin;
//
//            while (begin < s.size() && s[begin] == 0)
//            {
//                ++begin;
//            }
//
//        }
//
//        return -1;
//    }
//};
	// 方法二（学习过后的）
//class Solution {
//	 public:
//	     int firstUniqChar(string s) {
//	         int arr[256] = {};
//	         int i = 0;
//	         for (i = 0;i < s.size();i++)
//	         {
//	             ++arr[s[i]];
//	         }
//
//	         for (i = 0;i < s.size();i++)
//	         {
//	             if(arr[s[i]] == 1)
//	             {
//	                 return i;
//	             }
//	         }
//
//	         return -1;
//	     }
//	 };
	// 方法三（学习过后的）
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int arr[26] = {};
//        int i = 0;
//        for (i = 0; i < s.size(); i++)
//        {
//            ++arr[s[i] - 'a'];
//        }
//
//        for (i = 0; i < s.size(); i++)
//        {
//            if (arr[s[i] - 'a'] == 1)
//            {
//                return i;
//            }
//        }
//
//        return -1;
//    }
//};


	// 翻转二叉树（没通过，废案）（不破不立）（最后15min）
//void invertTree_(struct TreeNode* Left, struct TreeNode* Right,
//    struct TreeNode* PLeft, struct TreeNode* PRight) {
//    if (Right == NULL && Left == NULL)
//        return;
//
//    if (Right && Left)
//    {
//        int tmp = Right->val;
//        Right->val = Left->val;
//        Left->val = tmp;
//    }
//    else if (Right != NULL && Left == NULL)
//    {
//        PLeft->left = Right;
//        PRight->right = NULL;
//        invertTree_(Right->left, Right->right, Right, Right);
//        return;
//    }
//    else if (Right == NULL && Left != NULL)
//    {
//        PRight->right = Left;
//        PLeft->left = NULL;
//        invertTree_(Left->left, Left->right, Left, Left);
//        return;
//    }
//
//    invertTree_(Left->left, Right->right, Left, Right);
//
//    invertTree_(Left->right, Right->left, Left, Right);
//
//}
//
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if (root == NULL)
//        return NULL;
//
//    invertTree_(root->left, root->right, root, root);
//
//    return root;
//}
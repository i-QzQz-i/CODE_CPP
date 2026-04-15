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
	// 方法二（学习过后的）


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
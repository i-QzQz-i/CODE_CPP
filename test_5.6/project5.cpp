#define _CRT_SECURE_NO_WARNINGS 

	// 只出现一次的数据
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int sum = nums[0];
//
//        for (size_t i = 1; i < nums.size(); i++)
//        {
//            sum ^= nums[i];
//        }
//
//        return sum;
//    }
//};

	// 杨辉三角
	// 方法一、二
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv;
//        //vector<vector<int>> vv(numRows);
//
//        for (size_t i = 0; i < numRows; i++)
//        {
//            vector<int> v((i + 1), 1);
//            vv.push_back(v);
//            //vv[i].resize(i + 1, 1);
//        }
//
//        for (size_t i = 2; i < numRows; ++i)
//        {
//            for (size_t j = 1; j < vv[i].size() - 1; ++j)
//            {
//                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//            }
//        }
//
//        return vv;
//    }
//};

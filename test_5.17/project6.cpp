#define _CRT_SECURE_NO_WARNINGS 

    // 最小栈（设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈）
//class MinStack {
//public:
//    MinStack() {
//
//    }
//
//    void push(int val) {
//        st.push(val);
//        if (min_st.empty() || min_st.top() >= val)
//            min_st.push(val);
//    }
//
//    void pop() {
//        if (st.top() == min_st.top())
//            min_st.pop();
//
//        st.pop();
//    }
//
//    int top() {
//        return st.top();
//    }
//
//    int getMin() {
//        return min_st.top();
//    }
//
//private:
//    stack<int> st;
//    stack<int> min_st;
//};


    // 栈的压入、弹出序列
    // 思路1（找规律）（废案）
//bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
//    // write code here
//    if (pushV.size() == 1 && popV.back() == pushV.back())
//    {
//        return true;
//    }
//    if (pushV.size() == 1 && popV.back() != pushV.back())
//    {
//        return false;
//    }
//
//    int top1 = pushV.back();
//
//    vector<int>::iterator it = find(popV.begin(), popV.end(), top1) + 1;
//
//    while (it != popV.end() - 1 && it != popV.end() + 1)
//    {
//        if (find(pushV.begin(), pushV.end(), *it)
//            < find(pushV.begin(), pushV.end(), *(it + 1)))
//        {
//            return false;
//        }
//
//        ++it;
//    }
//
//    sort(pushV.begin(), pushV.end());
//    sort(popV.begin(), popV.end());
//    it = popV.begin();
//    for (int x : pushV)
//    {
//        if (x != *it)
//            return false;
//        ++it;
//    }
//
//    return true;
//}
//};
//  
    // 思路二（模拟进出栈）
//bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
//    // write code here
//    
//    stack<int> st;
//    size_t x = 0;
//    for (auto& e : pushV)
//    {
//        st.push(e);
//        while (!st.empty() && popV[x] == st.top())
//        {
//            st.pop();
//            ++x;
//        }
//    }
//
//    if (!st.empty())
//        return false;
//    else
//        return true;
//}
//};

//题目链接：https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-100-liked

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        //排序 + 依据重合条件更新区间
        //时间复杂度O(nlogn) -- 排序O(nlogn) 遍历数组O(n) 
        //空间复杂度O(logn) -- 排序所需的空间复杂度
        //两个区间重合的条件：一个区间的左端点小于等于另一个区间的右端点
        vector<vector<int>> ret;
        //进行排序，保证区间的覆盖是全面的
        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
        //进行循环判断区间是否重合
        for (int i = 1; i < intervals.size(); ++i)
        {
            //区间重合进行更新区间
            //一个区间的左端点小于等于另一个区间的右端点，进行更新区间
            if (intervals[i][0] <= ret.back()[1]) 
            {
                //更新区间的右端点（两个区间的右端点较大值）
                ret.back()[1] = max(intervals[i][1], ret.back()[1]);  
            }
            //区间不重合直接加入其中
            else ret.push_back(intervals[i]);
        }
        return ret;
    }
};
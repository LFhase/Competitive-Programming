/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.98%)
 * Total Accepted:    8.7K
 * Total Submissions: 29.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int flag = 0;
        for(int i=len-2;i>=0;--i)
        {
            if(nums[i]<nums[i+1])
            {
                flag = 1;
                sort(nums.begin()+i+1,nums.end());
                int idx = upper_bound(nums.begin()+i+1,nums.end(),nums[i])-nums.begin();
                //while(nums[idx]<=nums[i])    idx++;
                swap(nums[i],nums[idx]);
                break;
            }
        }
        if(!flag)   sort(nums.begin(),nums.end());
    }
};

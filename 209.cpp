//二分法
//Step1：满不满足二分本质 <=> 如果找到一个长度为6的子串和大于s，能否找到一个长度为7的子串和大于s（可以，因为题目中数组中是n个正整数）；如果不能找到一个长度为5的子串和大于s，能否找到一个长度为4的子串和大于s
//Step2：二分答案——子串的长度x => 能都存在长度为x的子串，和大于s

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //检查长度为mid的子串和是否大于等于target
    bool check(vector<int> &sum, const int s, int mid)
    {
        //Case1：包含开头元素的子串
        if (sum[mid - 1] >= s)
            return true; //长度为mid-1的子串和大于等于s，可以认为长度为mid的子串和大于s
        //Case2：不包含开头元素的子串
        for (int i = 1; i + mid - 1 < sum.size(); ++i)
            //枚举所有长度为mid的子串
            if (sum[i + mid - 1] - sum[i - 1] >= s) //长度为mid的子串下标区间为[1,mid]...[i,i+mid-1]的子串，其中有一个大于等于s即可
                return true;
        return false;
    }

    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sums(n);
        sums[0] = nums[0];
        for (int i = 1; i < n; ++i)
            sums[i] = nums[i] + sums[i - 1];
        int L = 0, R = n, mid, ans = 0;
        while (R > L)
        {
            mid = L + (R - L) / 2;
            if (check(sums, target, mid + 1))
            {
                R = mid;
                ans = mid + 1;
            }
            else
                L = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution ans;
    int target = 7;
    vector<int> nums;
    int tmp[] = {2, 3, 1, 2, 4, 3};
    for (int i = 0; i < 6; ++i)
    {
        nums.push_back(tmp[i]);
    }
    //输出结果
    int num;
    num = ans.minSubArrayLen(target, nums);
    cout << num << endl;
}
//二分法
//Step1：满不满足二分本质 <=> 如果能喂饱5个孩子，能不能喂饱4个孩子；如果不能喂饱6个孩子，能不能喂饱7个孩子
//Step2：二分答案——能满足的孩子个数x => 能否存在一个方案喂饱x个孩子。那么孩子应该挑什么样的孩子，饼干应该挑什么样的饼干
//Step3：孩子应该挑胃口最小的孩子，饼干应该挑份量最大的饼干 => 尝试用份量最大的x个饼干喂给胃口最小的x个孩子，同时最小分量对应胃口最小的孩子

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //检查是否能满足mid个孩子
    bool check(int mid, vector<int> &g, vector<int> &s)
    {
        if (g.size() < mid || s.size() < mid) //防止数组越界
            return false;
        for (int i = 0; i < mid; i++)
            if (g[i] > s[s.size() - mid + i]) //g的第i个与s的第|s|-mid+1个作比较，即看最大的mid个饼干能否喂饱最小的mid个孩子
                return false;
        return true;
    }
    //用二分法找能满足的孩子个数
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        //对两个向量进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //在孩子胃口向量（g）中进行二分查找
        int len1 = g.size();
        int L = 0, R = len1, mid;
        while (R > L)
        {
            mid = L + (R - L) / 2;    //mid的值永远[L,R)
            if (check(mid + 1, g, s)) //能满足mid+1个孩子时
                L = mid + 1;          //增大mid的值
            else
                R = mid; //减小mid的值
        }
        //返回最终值
        return L;
    }
};

int main()
{
    Solution ans;
    //定义两个向量并赋值
    vector<int> g, s;
    int tmp1[] = {1, 2, 3};
    for (int i = 0; i < 3; ++i)
    {
        g.push_back(tmp1[i]);
    }
    s.push_back(3);
    //输出结果
    int num;
    num = ans.findContentChildren(g, s);
    cout << num << endl;
}
//二分法
//Step1：满不满足二分本质 <=> 有3篇至少引用3次，那有没有2篇至少引用2次（有）；没有2篇至少引用2次，那有没有3篇至少引用3次（没有）
//Step2：二分答案——h指数 => 对于给定的hh，是否有h篇文章引用值至少是h => 挑引用量最高的h篇看一看

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int L = 0, R = n;
        while (L < R)
        {
            int mid = L + (R - L) / 2;
            if (citations[mid] >= n - mid)
                R = mid;
            else
                L = mid + 1;
        }
        return n - L;
    }
};

int main()
{
    Solution ans;
    //输入条件
    vector<int> citations;
    int tmp[] = {0, 1, 3, 5, 6};
    for (int i = 0; i < 5; ++i)
    {
        citations.push_back(tmp[i]);
    }
    //输出结果
    int num;
    num = ans.hIndex(citations);
    cout << num << endl;
}
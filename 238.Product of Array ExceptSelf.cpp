#include <iostream>
#include <vector>
using namespace std;

/*
分析存在的情况，只有3中情形，存在0的情况（多个0和一个0的情况）和不存在0的情况
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalMul = 1;
        vector<int> zeroCount;
        vector<int> output;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) == 0)
            {
                zeroCount.push_back(i);
                continue;
            }

            totalMul = totalMul * nums.at(i);
        }

        switch(zeroCount.size())
        {
            case 0:
                for(int i = 0; i < nums.size(); i++)
                {
                    output.push_back(totalMul/nums.at(i));
                }
                break;
            case 1:
                for(int i = 0; i < nums.size(); i++)
                {
                    if(nums.at(i) == 0)
                        output.push_back(totalMul);
                    else
                        output.push_back(0);
                }
                break;
            default:
                for(int i = 0; i < nums.size(); i++)
                {
                    output.push_back(0);
                }
        }
        return output;
    }
};

int main()
{
    int arr[] = {0,0};
    vector<int> vec(arr, arr+2);
    Solution s;
    vector<int> res = s.productExceptSelf(vec);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res.at(i) << endl;
    }
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());
        int i, j, k;
        int n = nums.size();
        int ret = nums.at(0) + nums.at(1) + nums.at(2);
        int minDelta = fabs(nums.at(0) + nums.at(1) + nums.at(2) - target);
        for(i = 0; i < n-2; i++)
        {
            if(i > 0 && nums.at(i) == nums.at(i-1))
                continue;

            j = i + 1;
            k = n - 1;
            while(j < k)
            {
                int sum = nums.at(i) + nums.at(j) + nums.at(k);
				if(sum == target) //不加这句会超时TimeLimitedOut
					return sum;
                if(fabs(sum - target) < minDelta)
                {
                    minDelta = fabs(sum - target);
                    ret = sum;
                }

                if(sum > target)
                    k--;
                if(sum < target)
                    j++;
            }
        }
        return ret;
    }
};

int main()
{
    int arr[] = {0, 1, 2, -3};
    vector<int> vec(arr, arr+4);
    int target = 1;
    Solution s;
    cout << s.threeSumClosest(vec, target) << endl;
}

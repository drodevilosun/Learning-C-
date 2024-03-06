#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct PricePos
{
    int price;
    int index;
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i-1] < prices[i])
            {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums = {7,1,5,3,6,4};
    int output = obj.maxProfit(nums);

    std::cout << output << std::endl;


    return 0;
}
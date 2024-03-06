#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pos = 0;
        int profit = 0;
        bool sorted = checkIsSorted(prices);
        if (prices.size() <= 1 ||
            (prices[0] - prices[1] > 0 &&
            sorted
            ))
            pos = 0;
        else
        {
            int price_min = prices[0];
            int n = prices.size();
            if (prices.size() == 2)
                profit = prices[1] - prices[0];
            else
                for (int i = 1; i < n; i++)
                {
                    if (prices[i] > price_min)
                    {
                        int curr_profit = prices[i] - price_min;
                        if (curr_profit > profit)
                        {
                            profit = curr_profit;
                            pos = i + 1;
                        }
                    }
                    else
                    {
                        price_min = prices[i];
                    }
                }
        }
        return profit;
    }
private:
    bool checkIsSorted(const vector<int>& arr)
    {
        bool asc = true;
        bool desc = true;
        for (size_t i = 1; i < arr.size(); i++)
        {
            if (asc == true && (arr[i] < arr[i - 1]))
                asc = false;
            if (desc == true && (arr[i] > arr[i - 1]))
                desc = false;
        }
        return asc | desc;
    }
};

// optimize version
int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int price : prices) {
        // Update the minimum price encountered so far
        minPrice = std::min(minPrice, price);

        // Update the maximum profit if the current price - minimum price is greater
        maxProfit = std::max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main()
{
    Solution obj;
    std::vector<int> nums = {2,1,4};
    int output = obj.maxProfit(nums);

    std::cout << output << std::endl;


    return 0;
}
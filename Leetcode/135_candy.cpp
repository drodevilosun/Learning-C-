#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 0;
        vector<int> candies (n, 1);
        // traverse form left to right
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                candies[i] += candies[i-1];
        }
        // traverse from right to left
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        for (int num : candies)
            sum += num;
        
        return sum;
    }
};

int main() {
    std::vector<int> ratings  = {1,3,2,2,1};
    Solution obj;

    int output = obj.candy(ratings);

    std::cout << "Number of candies is: " << output << std::endl;

    return 0;
}
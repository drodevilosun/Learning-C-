#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0; // Total gas in the tank
        int currGas = 0; // Current gas in the tank
        int startStation = 0; // Starting gas station index

        for (int i = 0; i < n; ++i) {
            totalGas += gas[i] - cost[i]; // Calculate total gas available after completing the circular route
            currGas += gas[i] - cost[i]; // Update the current gas in the tank

            // If the current gas becomes negative, reset the tank and update the starting station
            if (currGas < 0) {
                currGas = 0;
                startStation = i + 1; // Move to the next station as the starting point
            }
        }

        // If the total gas available is greater than or equal to zero, it means we can complete the circular journey
        if (totalGas >= 0) {
            return startStation;
        } else {
            return -1; // Otherwise, return -1 as there is no solution
        }
    }
};


int main() {
    std::vector<int> gas  = {2,3,4};
    std::vector<int> cost = {3,4,3};
    Solution obj;

    int output = obj.canCompleteCircuit(gas, cost);

    std::cout << "Starting gas station's index: " << output << std::endl;

    return 0;
}

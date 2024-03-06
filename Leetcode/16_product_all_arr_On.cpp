#include <iostream>
#include <vector>

using namespace std;

/*
Để giải bài toán này với độ phức tạp là On thì ta phải chi nó ra làm 2 phần và tránh phép chia
Khởi tạo 1 mảng answer n phần tử với initialize là 1: như vậy tích của các các phần tử khác trong mảng sẽ trừ đi chính nó
Left: Thực hiện tích các phần tử trong mảng và trừ đi chính nó (vì nó là 1 rồi):
    - multiply answer[i] với leftProduct ta sẽ được product của các phần tử trước đó ngoại trừ chính nó (1)
    - Lưu lại leftProduct đó bằng cách nhân với chính phần tử đang ở đó (chính nó) -> ta có tích của các phần tử trước đó 
    bao gồm nó để thực hiện phép tính nhân cho phần tử tiếp theo
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer (n, 1);
        int leftProduct = 1;
        for (int i = 0; i < n; i++)
        {
            answer[i]   *= leftProduct;
            leftProduct *= nums[i];
        }
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            answer[i]    *= rightProduct;
            rightProduct *= nums[i];
        }
        return answer;
    }
};


int main()
{
    Solution obj;
    std::vector<int> nums = {1,2,3,4};
    vector<int> output = obj.productExceptSelf(nums);

    // std::cout << output << std::endl;


    return 0;
}
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// A utility function to swap two elements



class Solution
{
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while(mid <= high)
        {

            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1){
                ++mid;
            }
            else{
                swap(nums[mid++], nums[high--]);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);

    // Print sorted array
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
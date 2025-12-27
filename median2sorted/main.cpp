#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &arr, int left,
               int mid, int right)
    {

        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temp vectors
        vector<int> L(n1), R(n2);

        // Copy data to temp vectors L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;

        // Merge the temp vectors back BUT NOT ALL ELEMENTS JUST OVER HALF
        // into arr[left..right]
        while (i < n1 && j < n2 && k <= ((left + right) / 2)+1)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        // Copy the remaining elements of L[],
        // if there are any
        while (i < n1 && k <= ((left + right) / 2)+1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[],
        // if there are any
        while (j < n2 && k <= ((left + right) / 2)+1)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        const int totalSize = n1 + n2;

        vector<int> arr = nums1;
        arr.insert(arr.end(), nums2.begin(), nums2.end());
        merge(arr, 0, n1 - 1, totalSize - 1);
        if (totalSize % 2 == 0)
        {
            return (arr[totalSize / 2 - 1] + arr[totalSize / 2]) / 2.0;
        }
        else
        {
            return arr[totalSize / 2];
        }
    }
};

int main()
{
    Solution s;
    vector<pair<vector<int>, vector<int>>> nums = {
        {{1, 3}, {2}},
        {{1, 2}, {3, 4}},
        {{0, 0}, {0, 0}},
        {{}, {1}},
        {{2}, {}}};

    for (auto num : nums)
        cout << s.findMedianSortedArrays(num.first, num.second) << endl;
    return 0;
}
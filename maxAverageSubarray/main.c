#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

double findMaxAverage(int *nums, int numsSize, int k)
{
    int left = 0;
    int right = k - 1;
    double max_avg = 0;
    double nums_double[numsSize];
    for(int i = 0; i < numsSize; ++i) {
        nums_double[i] = (double)nums[i]/k;
        if(i < k) max_avg += nums_double[i];
    }
    double curr_avg = max_avg;
    while (right < numsSize - 1)
    {
        curr_avg += nums_double[++right]-nums_double[left++];
        if (max_avg < curr_avg)
        {
            max_avg = curr_avg;
        }
    }
    return max_avg;
}


int main()
{
    int nums[] = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = findMaxAverage(nums, 6, k);
    printf("Max average subarray: %f\n", result);

    return 0;
}
#include <stdio.h>
#include <time.h>

/*
    name: Maximum Subarray
*/
int maxSubArrayOld(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 1) {
        return 0;
    }
    int i, sum = nums[0], maxSum = nums[0];
    for (i = 1; i < numsSize; ++i) {
        if (sum < 0) {
            sum = nums[i];
        } else {
            sum += nums[i];
        }
        //update max
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int maxSubArray(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 1) {
        return 0;
    }
    int i, max;
    int dp[numsSize];
    dp[0] = nums[0];
    max = nums[0];
    for (i = 1; i < numsSize; ++i) {
        dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        if (max < dp[i]) {
            max = dp[i];
        }
    }
    return max;
}

/*test unit*/
int main(int argc, char const *argv[]){
    int nums1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int nums[] = {-2, -1, -3, -4};
    clock_t start, end;
    start = clock();
    printf("dp = %d\n", maxSubArray(nums, 4));
    end = clock();
    printf("time = %lf\n", 1000 * (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
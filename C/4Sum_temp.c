#include <stdio.h>
#include <stdlib.h>

/*
	name: compareter
*/
int mycomp(const void* p1, const void* p2) {
	return *(const int*)p1 - *(const int*)p2;
}

/*
	Return an array of arrays of size *returnSize.
	Note: The returned array must be malloced, assume caller calls free().
	notes:
		1.在 3sum 的基础上使用 hash 表进行在线性时间内查找
*/
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	if (numsSize < 4 || nums == NULL) {
		return NULL;
	}
	qsort(nums, numsSize, sizeof(nums[0]), mycomp);
    int** res = NULL;
    int count = 0;
    int i, j, k, l;
    int sum = 0;
    for (k = 0; k < numsSize - 3; ++k) {
    	//去重
    	if (nums[k] > target) {
    		break;
    	}
    	//去重
    	while (k > 0 && nums[k] == nums[k - 1]) {
    		++k;
    	}
    	for (l = k + 1; l < numsSize - 2; ++l) {
    		while (l > k + 1 && nums[l] == nums[l - 1]) {
    			++l;
    		}
    		i = l + 1;
    		j = numsSize - 1;
    		while (i < j) {
    			sum = nums[i] + nums[j] + nums[k] + nums[l];
    			if (sum == target) {
    				//去重
    				if (count > 0 && res[count - 1][0] == nums[k] && res[count - 1][1] == nums[l] && res[count -1][2] == nums[i] && res[count - 1][3] == nums[j]) {
    					++i;
    					--j;
    					continue;
    				}
    				++count;
    				res = (int**)realloc(res, sizeof(int*) * count);
    				res[count - 1] = (int*)malloc(sizeof(int) * 4);
    				res[count - 1][0] = nums[k];
    				res[count - 1][1] = nums[l];
    				res[count - 1][2] = nums[i];
    				res[count - 1][3] = nums[j];
    				/*while (i < j && nums[i] == nums[i - 1]) {
    					++i;
    				}
    				while (i < j && nums[j] == nums[j + 1]) {
    					--j;
    				}*/
    				++i;
    				--j;
    			} else if (sum < target) {
    				++i;
    			} else {
    				--j;
    			}
    		}
    	}
    }
    *returnSize = count;
    return res;
}

/*test unit*/
int main(int argc, char const *argv[]){
	int nums2[] = {-5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5};
	int nums1[] = {1, 0, -1, 0, -2, 2};
	int nums[] = {-7, -5, 0, 7, 1, 1, -10, -2, 7, 7, -2, -6, 0, -10, -5, 7, -8, 5};
	int n;
	int** p = fourSum(nums, 18, 28, &n);
	printf("%d\n", n);
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < 3; ++j) {
			printf("%d --> ", p[i][j]);
		}
		printf("%d\n", p[i][j]);
	}
	return 0;
}
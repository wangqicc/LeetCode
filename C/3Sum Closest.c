#include <stdio.h>
#include <stdlib.h>	//provide qsort(p, n, type_size, mycomp);
#define abs(x) x > 0 ? x : -x

/*
	name: my compare function
*/
int mycomp(const void* p1, const void* p2) {
	return *(const int*)p1 - *(const int*)p2;
}

/*
	name: 3Sum Closest
*/
int threeSumClosest(int* nums, int numsSize, int target) {
	qsort(nums, numsSize, sizeof(nums[0]), mycomp);
	int i, j, k;
	int closest = nums[0] + nums[1] + nums[numsSize - 1];
	int sum;
	for (k = 0; k < numsSize - 2; ++k) {
		i = k + 1;
		j = numsSize - 1;
		while (i < j) {
			sum = nums[i] + nums[j] + nums[k];
			/*if (sum < target) {
				++i;
			} else {
				--j;
			}*/
			//replaced by a 3-tuple expression
			sum < target ? ++i : --j;
			if (abs(sum - target) < abs(closest - target)) {
				closest = sum;
			}
		}
	}
    return closest;
}


/*test unit*/
int main(int argc, char const *argv[]){
	int nums[] = {-1, 2, 1, -4};
	int nums1[] = {2, -1, 0, 1};
	printf("closet = %d\n", threeSumClosest(nums1, 4, 5));
	return 0;
}
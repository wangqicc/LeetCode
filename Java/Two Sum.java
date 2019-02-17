import java.util.Map;
import java.util.HashMap;
class Solution {
    //normal solution
    public int[] twoSumOne(int[] nums, int target) {
        int[] result = new int[2];
        for (int i = 0; i < nums.length; ++i) {
        	for (int j = i + 1; j < nums.length; ++j) {
        		if (nums[i] + nums[j] == target) {
        			result[0] = i;
        			result[1] = j;
        			return result;
        		}
        	}
        }
        return result;
    }

    //Use HashMap to making this problem to linear time
    public int[] twoSumTwo(int[] nums, int target) {
    	int[] result = new int[2];
    	Map<Integer, Integer> map = new HashMap<Integer, Integer>();

    	for (int i = 0; i < nums.length; ++ i) {
    		if (map.containsKey(target - nums[i])) {
    			result[0] = i;
    			result[1] = map.get(target - nums[i]);
    			return result;
    		}
    		map.put(nums[i], i);
    	}

    	return result;
    }

    //Test Unit
    public static void main(String[] args) {
    	int[] nums = {2, 7, 11, 15};
    	int target = 18;

    	Solution solution = new Solution();
    	int[] a = solution.twoSumTwo(nums, target);

    	System.out.println("ans = " + a[0] + " " + a[1]);
    }
}

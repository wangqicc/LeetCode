import java.util.*;
class Solution {
    public int reverse(int x) {
        int result = 0;
        int newResult = 0;
        int remainder = 0;

        while (x != 0) {
        	remainder = x % 10;
        	newResult = result * 10 + remainder;
        	//check result whether overflow or not
        	if ((newResult - remainder) / 10 != result) {
        		return 0;
        	}
        	result = newResult;
        	x /= 10;
        }

        return result;
    }
    //test unit
    public static void main(String[] args) {
    	Solution solution = new Solution();
    	Scanner cin = new Scanner(System.in);
    	int x;
    	while (cin.hasNext()) {
    		x = cin.nextInt();
    		System.out.println(solution.reverse(x));
    	}
    	cin.close();
    }
}

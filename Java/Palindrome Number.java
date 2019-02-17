import java.util.*;
class Solution {
    //check 123454321 will finally check if 12345432 == 123454321 / 10 and 
    //1 == 123454321 % 10
    public boolean isPalindrome(int x) {
        if (x < 0) {
        	return false;
        }
        int revX = 0;
        int copyX = x;
        while (copyX > 9) {
        	revX = revX * 10 + copyX % 10;
        	copyX /= 10;
        }
        return revX == x / 10 && copyX == x % 10;
    }
    //test unit
    public static void main(String[] args) {
    	Solution solution = new Solution();
    	Scanner cin = new Scanner(System.in);
    	int x;
    	while (cin.hasNext()) {
    		x = cin.nextInt();
    		System.out.println(solution.isPalindrome(x));
    	}
    	cin.close();
    }
}

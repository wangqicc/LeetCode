class Solution {
	public int romanToInt(String s) {
		int length = s.length();
		int[] a = new int[length];
		for (int i = 0; i < length; ++i) {
			switch (s.charAt(i)) {
				case 'I':
					a[i] = 1;
					break;
				case 'V':
					a[i] = 5;
					break;
				case 'X':
					a[i] = 10;
					break;
				case 'L':
					a[i] = 50;
					break;
				case 'C':
					a[i] = 100;
					break;
				case 'D':
					a[i] = 500;
					break;
				case 'M':
					a[i] = 1000;
					break;
			}
		}
		int result = 0;
		for (int i = 0; i < length - 1; ++i) {
			if (a[i] < a[i + 1]) {
				result -= a[i];
			} else {
				result += a[i];
			}
		}
		result += a[length - 1];
		return result;
    }
    //test unit
    public static void main(String[] args) {
    	Solution solution = new Solution();
    	System.out.println(solution.romanToInt("III"));
    	System.out.println(solution.romanToInt("IV"));
    	System.out.println(solution.romanToInt("IX"));
    	System.out.println(solution.romanToInt("LVIII"));
    	System.out.println(solution.romanToInt("MCMXCIV"));
    }
}

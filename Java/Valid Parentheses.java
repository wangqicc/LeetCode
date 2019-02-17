class Solution {
	public boolean isValid(String s) {
        int length = s.length();
        char[] stack = new char[length];
        int top = -1;

        for (char c : s.toCharArray()) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    stack[++top] = c;
                    break;
                case ')':
                    if (top == -1 || stack[top--] != '(') {
                        return false;
                    }
                    break;
                case ']':
                    if (top == -1 || stack[top--] != '[') {
                        return false;
                    }
                    break;
                case '}':
                    if (top == -1 || stack[top--] != '{') {
                        return false;
                    }
                    break;
            }
        }
        
        return top == -1;
    }
    //test unit
    public static void main(String[] args) {
    	Solution solution = new Solution();
    	System.out.println(solution.isValid(")"));//return false
        System.out.println(solution.isValid("({})"));//return true
        System.out.println(solution.isValid("()[]{}"));//return true
        System.out.println(solution.isValid("(]"));//return false
    }
}

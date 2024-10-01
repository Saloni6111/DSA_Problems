import java.util.Stack;

public class ValidParentheses {

    public static boolean isValid(String s) {
        // Stack to keep track of opening brackets
        Stack<Character> stack = new Stack<>();

        // Iterate through each character in the string
        for (char c : s.toCharArray()) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            // If it's a closing bracket, check if it matches the top of the stack
            else if (c == ')' && !stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            } else if (c == '}' && !stack.isEmpty() && stack.peek() == '{') {
                stack.pop();
            } else if (c == ']' && !stack.isEmpty() && stack.peek() == '[') {
                stack.pop();
            }
            // If it doesn't match or the stack is empty, it's invalid
            else {
                return false;
            }
        }

        // If the stack is empty, all brackets were matched, so the string is valid
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        String test = "([{}])";
        if (isValid(test)) {
            System.out.println("The string is valid.");
        } else {
            System.out.println("The string is invalid.");
        }
    }
}

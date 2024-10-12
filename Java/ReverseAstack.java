/*
    Question: Reverse a stack using Recursion (Level : Medium)
    *****************************************
    Reference: https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack
    ------------------------------------------------------------------------------------- 
    You are given a stack s. You have to reverse the stack using recursion.

    // Example 1:

    Input:
    s = {3,2,1,7,6}
    Output:
    {6,7,1,2,3}
    Explanation:
    Input stack after reversing will look like the stack in the output.
    
    // Example 2:

    Input:
    s = {4,3,9,6}
    Output:
    {6,9,3,4}
    Explanation:
    Input stack after reversing will look like the stack in the output.

    Expected Time Complexity: O(N^2)
    Expected Auxiliary Space: O(1)

    Constraints:
    1 <= size of the stack <= 10^4
    -109 <= Each element of the stack <= 10^9
    Sum of N over all test cases doesn't exceeds 10^6
    Array may contain duplicate elements. 
    ------------------------------------------------------------------------------------- 
 */


class Solution
{ 
    static void reverse(Stack<Integer> s)
    {
        // add your code here
        // Base case: If stack is empty, return.
        if (s.isEmpty()) {
            return;
        }

        // Remove the top element from the stack.
        int num = s.pop();

        // Recursively call reverse for the remaining elements.
        reverse(s);

        // Place the removed element at the bottom of the stack.
        bottom(s, num);
    }

    // Static method to place an element at the bottom of the stack.
    static void bottom(Stack<Integer> s, int num) {
        // Base case: If stack is empty, push the element.
        if (s.isEmpty()) {
            s.push(num);
            return;
        }

        // Remove the top element from the stack.
        int top = s.pop();

        // Recursively call bottom to reach the base of the stack.
        bottom(s, num);

        // Push the top element back.
        s.push(top);
    }
}

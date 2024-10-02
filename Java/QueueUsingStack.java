import java.util.*;

public class QueueUsingStack {
    public static class StackQueue {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        
        void add(int val) {
            s1.push(val);
        }
        
        int remove() {
            if(s1.size() == 0) {
                return -1;
            }
            
            for(int i=0; i<s1.size()-1; i++) { //move n-1 elements from s1 to s2
                s2.push(s1.pop());
            }
            
            int ans = s1.pop();
            for(int i=0; i<s2.size(); i++) { //move all elements from s2 to s1
                s1.push(s2.pop());
            }
        
            return ans;
        }
    }

    public static void main(String[] args) {
        StackQueue sq = new StackQueue();

        sq.add(10);
        sq.add(20);
        sq.add(30);

        System.out.println(sq.remove());
        System.out.println(sq.remove());

        sq.add(40);
        System.out.println(sq.remove());
        System.out.println(sq.remove());
    }
}

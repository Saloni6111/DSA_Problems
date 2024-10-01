import java.util.*;

class Solution {
    public static boolean canFinish(int n, int[][] pr) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int indegree[] = new int[n];
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int x[] : pr) {
            adj.get(x[0]).add(x[1]);
            indegree[x[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            int x = indegree[i];
            if (x == 0)
                q.add(i);
        }
        while (q.size() > 0) {
            int curr = q.poll();
            for (int x : adj.get(curr)) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.add(x);
                }
            }
        }
        for (int x : indegree) {
            if (x != 0)
                return false;
        }
        return true;
    }
    public static void main(String[] args) {
        
    }
}

public class Course_Schedule {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the size of the array
        System.out.print("Enter number of courses: ");
        int n = sc.nextInt();

        // Initialize the array
        int arr[][] = new int[n][2];
        int i=0;
        int x=0;
        do{
        System.out.println("Enter the prerequisites:");
        arr[i][0]=sc.nextInt();
        arr[i][1]=sc.nextInt();
        System.out.println("Press 0 to enter more prerequisites:");
         x=sc.nextInt();
         i++;
    }while(x==0);

        // Call fanFind function
        boolean res=Solution.canFinish(n,arr);

        if(res){
            System.out.println("True");
        }else{
            System.out.println("False");
        }

        sc.close();
    }
}
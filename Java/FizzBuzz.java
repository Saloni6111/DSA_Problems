import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class FizzBuzz {
    public static List<String> fizzBuzz(int n) {
        List<String> result = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                result.add("FizzBuzz");
            } else if (i % 3 == 0) {
                result.add("Fizz");
            } else if (i % 5 == 0) {
                result.add("Buzz");
            } else {
                result.add(Integer.toString(i));
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input from the user
        System.out.print("Enter the value of n: ");
        int n = scanner.nextInt();

        // Get the FizzBuzz result
        List<String> output = fizzBuzz(n);

        // Print the result
        for (String s : output) {
            System.out.print(s + " ");
        }

        System.out.println();
        scanner.close();
    }
}

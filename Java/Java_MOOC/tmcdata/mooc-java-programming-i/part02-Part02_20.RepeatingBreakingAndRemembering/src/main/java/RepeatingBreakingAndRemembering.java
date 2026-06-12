
import java.util.Scanner;

public class RepeatingBreakingAndRemembering {

    public static void main(String[] args) {
        
        // This exercise is worth five exercise points, and it is 
        // gradually extended part by part.
        
        // If you want, you can send this exercise to the server
        // when it's just partially done. In that case the server will complain about 
        // the parts you haven't done, but you'll get points for the finished parts.
        
        Scanner scanner = new Scanner(System.in);
        
        int sum = 0, i = 0, evenCount = 0, oddCount = 0;
        float ave;

        System.out.println("Give numbers:");
        while (true) { 
            int x = Integer.valueOf(scanner.nextLine());

            if (x == -1) {
                break;
            } else if (x % 2 == 0 && x != 0) {
                evenCount++;
            } else {
                oddCount++;
            }

            sum = sum + x;
            i++;
        }

        ave = (float) sum/i;

        System.out.print("Thx! Bye! ");

        if (sum != 0) {
            System.out.println("Sum: " + sum);
            System.out.println("Numbers: " + i);
            System.out.println("Average: " + ave);
            System.out.println("Even: " + evenCount);
            System.out.println("Odd: " + oddCount);
        }

    }
}

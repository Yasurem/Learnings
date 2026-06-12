
import java.util.Scanner;

public class NumberAndSumOfNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int i = 0;
        int total = 0;

        while (true) { 
            System.out.println("Give a number:");
            int x = Integer.valueOf(scanner.nextLine());
            
            if (x == 0) {
                break;
            }

            i++;
            total = total + x;
        }
        System.out.println("Number of numbers: " + i);
        System.out.println("Sum of the numbers: " + total);
    }
}

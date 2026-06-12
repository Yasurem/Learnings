
import java.util.Scanner;

public class SumOfTwoNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Write your program here
        int first, second;
        System.out.println("Give the first number:");
        first = Integer.valueOf(scanner.nextLine());

        System.out.println("Give the second number:");
        second = Integer.valueOf(scanner.nextLine());

        System.out.println("The sum of the numbers is " + (first + second));
    }
}

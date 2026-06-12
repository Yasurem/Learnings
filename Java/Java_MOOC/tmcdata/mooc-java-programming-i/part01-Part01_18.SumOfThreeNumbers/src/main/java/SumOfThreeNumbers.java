
import java.util.Scanner;

public class SumOfThreeNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Write your program here
        int first, second, third;

        System.out.println("Give the first number:");
        first = Integer.valueOf(scanner.nextLine());

        System.out.println("Give the second number:");
        second = Integer.valueOf(scanner.nextLine());

        System.out.println("Give the third number:");
        third = Integer.valueOf(scanner.nextLine());

        System.out.println("The sum of the numbers is " + (first + second + third));
        
    }
}

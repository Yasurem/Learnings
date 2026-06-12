
import java.util.Scanner;

public class AverageOfThreeNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Write your program here
        int x, y, z;

        System.out.println("Give the first number:");
        x = Integer.valueOf(scanner.nextLine());

        System.out.println("Give the second number:");
        y = Integer.valueOf(scanner.nextLine());

        System.out.println("Give the third number:");
        z = Integer.valueOf(scanner.nextLine());

        System.out.println("The average is " + ((double) (x + y + z) / 3.0));
    }
}

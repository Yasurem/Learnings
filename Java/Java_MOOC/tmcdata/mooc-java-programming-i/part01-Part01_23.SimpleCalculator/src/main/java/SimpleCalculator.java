
import java.util.Scanner;

public class SimpleCalculator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Write your program here
        int x, y;

        System.out.println("Give the first number:");
        x = Integer.valueOf(scanner.nextLine());

        System.out.println("Give the second number:");
        y = Integer.valueOf(scanner.nextLine());

        System.out.println(x + " + " + y + " = " + (x + y));
        System.out.println(x + " - " + y + " = " + (x - y));
        System.out.println(x + " * " + y + " = " + (x * y));
        System.out.println(x + " / " + y + " = " + ((float) x / y));
    }
}

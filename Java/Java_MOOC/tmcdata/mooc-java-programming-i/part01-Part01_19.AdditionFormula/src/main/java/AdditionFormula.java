
import java.util.Scanner;

public class AdditionFormula {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // write your program here
        int first, second;
        System.out.println("Give the first number:");
        first = Integer.valueOf(scanner.nextLine());

        System.out.println("Give the second number:");
        second = Integer.valueOf(scanner.nextLine());

        System.out.println(first + " + " + second + " = " + (first + second));
    }
}

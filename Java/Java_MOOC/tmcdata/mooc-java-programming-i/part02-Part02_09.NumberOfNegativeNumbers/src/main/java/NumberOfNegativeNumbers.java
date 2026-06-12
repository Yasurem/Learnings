
import java.util.Scanner;

public class NumberOfNegativeNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int i = 0;
        while (true) { 
            // User Input
            System.out.println("Give a number:");
            int x = Integer.valueOf(scanner.nextLine());

            // If 0, break, i--
            if (x == 0) {
                break;
            } else if (x < 0) {
                i++;
            }
        }
        System.out.println("Number of negative numbers: " + i);
    }
}

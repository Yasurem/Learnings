
import java.util.Scanner;

public class NumberOfNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int i = 0;
        while (true) { 
            System.out.println("Give a number:");
            int userIn = Integer.valueOf(scanner.nextLine());
            i++;

            if (userIn == 0) {
                i--;
                break;
            }
        }
        System.out.println("Number of numbers: " + i);
    }
}

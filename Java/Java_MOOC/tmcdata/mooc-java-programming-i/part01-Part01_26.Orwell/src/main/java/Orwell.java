
import java.util.Scanner;

public class Orwell {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // Write your program here
        System.out.println("Give a number:");
        if (1984 == Integer.valueOf(scan.nextLine())) {
            System.out.println("Orwell");
        }
    }
}

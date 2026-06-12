
import java.util.Scanner;

public class Same {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // Write your program here. 
        String a, b;

        System.out.println("Enter the first string:");
        a = scan.nextLine();

        System.out.println("Enter the second string:");
        b = scan.nextLine();

        if (a.equals(b)) {
            System.out.println("Same");
        } else {
            System.out.println("Different");
        }
    }
}


import java.util.Scanner;

public class Greeting {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Write your program here
        System.out.println("What's your name?");

        String username = scanner.nextLine();

        System.out.println("Hi " + username);
    }
}

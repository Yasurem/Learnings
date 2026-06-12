
import java.util.Scanner;

public class Conversation {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String greet = "Greetings! How are you doing?";
        String reply = "Oh, how interesting. Tell me more!";
        String closing = "Thanks for sharing!";

        // Write your program here
        System.out.println(greet);
        scanner.nextLine();

        System.out.println(reply);
        scanner.nextLine();

        System.out.println(closing);
    }
}

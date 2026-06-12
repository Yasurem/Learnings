
import java.util.Scanner;

public class SecondsInADay {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Write your program here
        int days, hrs = 24, min = 60, secIn = 60, secOut;
        System.out.println("How many days would you like to convert to seconds?");
        days = Integer.valueOf(scanner.nextLine());

        secOut = days * hrs * min * secIn;
        System.out.println(secOut);
    }
}

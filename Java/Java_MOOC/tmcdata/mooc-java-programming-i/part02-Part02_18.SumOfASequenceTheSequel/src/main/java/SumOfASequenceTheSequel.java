
import java.util.Scanner;

public class SumOfASequenceTheSequel {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("First number? ");
        int in = Integer.valueOf(scanner.nextLine());

        System.out.print("Last number? ");
        int out = Integer.valueOf(scanner.nextLine());

        int sum = 0;
        for (int i = in; i <= out; i++) {
            sum = sum + i;
        }
        System.out.print("The sum is " + sum);
    }
}

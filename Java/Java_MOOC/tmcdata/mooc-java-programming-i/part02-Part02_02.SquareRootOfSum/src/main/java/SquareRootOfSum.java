
import java.util.Scanner;

public class SquareRootOfSum {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, y;

        x = Integer.valueOf(scanner.nextLine());
        y = Integer.valueOf(scanner.nextLine());

        System.out.println(Math.sqrt(x + y));
    }
}

import java.util.Scanner;

public class AbsoluteValue {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int x = Integer.valueOf(scan.nextLine());

        if (x < 0) {
            System.out.println(x * -1);
        } else {
            System.out.println(x);
        }
    }
}
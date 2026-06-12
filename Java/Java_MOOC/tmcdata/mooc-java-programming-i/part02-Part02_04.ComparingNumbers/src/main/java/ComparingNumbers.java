import java.util.Scanner;

public class ComparingNumbers {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int x, y;

        x = Integer.valueOf(scan.nextLine());
        y = Integer.valueOf(scan.nextLine());
        
        if (x > y) {
            System.out.println(x + " is greater than the " + y);
        } else if (y > x) {
            System.out.println(x + " is smaller than the second than " + y);
        } else {
            System.out.println("The " + x + " is equal to " + y);
        }
    }
}
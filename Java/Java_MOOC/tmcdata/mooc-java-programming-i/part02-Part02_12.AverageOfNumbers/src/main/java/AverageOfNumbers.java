
import java.util.Scanner;

public class AverageOfNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        float ave;
        int i = 0, total = 0;
        while (true) { 
            System.out.println("Give a number:");
            int x = Integer.valueOf(scanner.nextLine());

            if (x == 0) {
                break;
            }

            total = total + x;
            i++;
        }

        ave = (float) total/i;
        System.out.println("Average of the numbers: " + ave);
    }
}

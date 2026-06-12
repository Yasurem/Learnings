
import java.util.Scanner;

public class GradesAndPoints {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int grade;
        System.out.println("Give points [0 - 100]:");
        grade = Integer.valueOf(scan.nextLine());

        if (grade < 0) {
            System.out.println("impossible!");
        } else if (grade > -1 && grade < 50) {
            System.out.println("failed");
        } else if (grade > 49 && grade < 60) {
            System.out.println("1");
        } else if (grade > 59 && grade < 70) {
            System.out.println("2");
        } else if (grade > 69 && grade < 80) {
            System.out.println("3");
        } else if (grade > 79 && grade < 90) {
            System.out.println("4");
        } else if (grade > 89 && grade < 101) {
            System.out.println("5");
        } else {
            System.out.println("incredible!");
        }
    }
}

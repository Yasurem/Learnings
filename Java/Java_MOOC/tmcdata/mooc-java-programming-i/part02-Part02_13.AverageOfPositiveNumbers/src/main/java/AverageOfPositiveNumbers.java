
import java.util.Scanner;

public class AverageOfPositiveNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int total = 0, i = 0, x;
        float ave;
        while (true) { 
            x = Integer.valueOf(scanner.nextLine());

            if ((total == 0 && x == 0)) {
                System.out.println("Cannot calculate the average");
                break;              
            } else if (x == 0) {
                break;
            } else if (x > 0) {
                i++;
                total = total + x;
            }
        }

        if (total != 0) {
            ave = (float) total / i;
            System.out.println(ave);    
        }
        
    }
}

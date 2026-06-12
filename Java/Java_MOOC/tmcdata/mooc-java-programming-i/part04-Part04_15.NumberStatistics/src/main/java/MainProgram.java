
import java.util.Scanner;

public class MainProgram {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // you can write test code here
        // however, remove all unnecessary code when doing the final parts of the exercise

        // In order for the tests to work, the objects must be created in the
        // correct order in the main program. First the object that tracks the total
        // sum, secondly the object that tracks the sum of even numbers, 
        // and lastly the one that tracks the sum of odd numbers!
        Statistics sumAll = new Statistics();
        Statistics sumEven = new Statistics();
        Statistics sumOdd = new Statistics();

        System.out.print("Enter numbers: ");
        
        while (true) {
            int userInput = Integer.valueOf(scanner.nextLine());
            if (userInput == -1) {
                break;
            }

            sumAll.addNumber(userInput);
            if (userInput % 2 == 0) {
                sumEven.addNumber(userInput);
            } else {
                sumOdd.addNumber(userInput);                
            }
        }

        System.out.println("Sum: " + sumAll.sum() + " Sum of even numbers: " + sumEven.sum() + " Sum of Odd number: " + sumOdd.sum());
    }
}

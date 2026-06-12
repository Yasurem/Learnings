import java.util.Scanner;

public class InAHoleInTheGround {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        printText(scanner);

    }

    public static void printText(Scanner scanner) {
        System.out.println("In a hole in the ground there lived a method");
        String txt = scanner.nextLine();
    }
}
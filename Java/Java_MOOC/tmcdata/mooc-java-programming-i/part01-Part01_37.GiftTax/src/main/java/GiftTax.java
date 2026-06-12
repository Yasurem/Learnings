
import java.util.Scanner;

public class GiftTax {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        double valueGift, valueLower, rate, taxLower, taxFinal;

        System.out.println("Value of the gift?");
        valueGift = Double.valueOf(scan.nextLine());

        if (valueGift < 5000) {
            System.out.println("No tax!");
            return;
        } else if (valueGift < 25001) {
            valueLower = 5000;
            taxLower = 100;
            rate = 0.08;
        } else if (valueGift < 55001) {
            valueLower = 25000;
            taxLower = 1700;
            rate = 0.1;
        } else if (valueGift < 200001) {
            valueLower = 55000;
            taxLower = 4700;
            rate = 0.12;
        } else if (valueGift < 1000001) {
            valueLower = 200000;
            taxLower = 22100;
            rate = 0.15;
        } else { 
            valueLower = 1000000;
            taxLower = 142100;
            rate = 0.17;
        }

        taxFinal = (taxLower + (valueGift - valueLower) * rate);
        System.out.println("Tax: " + taxFinal);
    }
}

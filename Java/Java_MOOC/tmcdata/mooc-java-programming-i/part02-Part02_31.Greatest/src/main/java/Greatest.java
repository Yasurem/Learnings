
public class Greatest {

    public static int greatest(int number1, int number2, int number3) {
        
        //write some code here
        int highest = number1;
        int num[] = { number1, number2, number3 };

        for (int i = 0; i < 3; i++) {
            if (highest < num[i]) {
                highest = num[i];
            }
        }
        return highest;
    }

    public static void main(String[] args) {
        int result = greatest(2, 7, 3);
        System.out.println("Greatest: " + result);
    }
}

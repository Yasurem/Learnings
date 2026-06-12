
public class YourFirstBankTransfer {

    public static void main(String[] args) {
    // Do not touch the code in Account.java
    // write your program here
        // Creates an account named "Matthews account"with the balance 1000
        Account matthewsAccount = new Account("Matthews account",  1000);

        // Creates an account named "My account"with the balance 0
        Account myAccount = new Account("My account", 0);

        // Withdraws 100.0 from Matthew's account
        matthewsAccount.withdrawal(100.0);

        // Deposits 100.0 to "my account"
        myAccount.deposit(100.0);

        // Prints both accounts
        System.out.println(matthewsAccount);
        System.out.println(myAccount);
    }
}

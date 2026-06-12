/* 
 * DO NOT TOUCH THIS !
 */

public class Account {

    private double balance;
    private String owner;

    // Setter
    public Account(String owner, double balance) {
        this.balance = balance;
        this.owner = owner;
    }

    // Setter
    public void deposit(double amount) {
        this.balance = this.balance + amount;
    }

    // Setter
    public void withdrawal(double amount) {
        this.balance = this.balance - amount;
    }

    // Setter
    public double saldo() {
        return this.balance;
    }

    // Getter *Interesting!*
    @Override
    public String toString() {
        return this.owner + " balance: " + this.balance;
    }
}

package JavaGUI;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class PUPLagoonStore extends JFrame implements ActionListener{
    JLabel appName, customerName, courseName, itemsLabel, discountLabel, totalLabel, moneyInserted, changeLabel, vatLabel;
    JTextField customerNameField, courseNameField, moneyInsertedField;
    JCheckBox shake, fewa, siomaiRice, noodles, hotcake, chickenRice, gulaman, water;
    JRadioButton pwd, senior, noDisc;
    ButtonGroup discountButtonGroup;
    JTextArea totalFeeArea, changeFeeArea, vatArea;
    JButton compute, cancel;
    double totalPrice;
    double change;
    double vat;

    PUPLagoonStore() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("PUP Lagoon Store System");
        this.setLayout(new BorderLayout());
        
        appName = new JLabel("PUP Lagoon Store");
        appName.setFont(new Font("Times New Roman", Font.BOLD, 30));
        
        customerName = new JLabel("NAME:");
        courseName = new JLabel("COURSE:");
        
        itemsLabel = new JLabel("ITEMS:");
        discountLabel = new JLabel("DISCOUNT:");
        totalLabel = new JLabel("TOTAL:");
        moneyInserted = new JLabel("MONEY INSERTED:");
        changeLabel = new JLabel("CHANGE:");
        vatLabel = new JLabel("VAT:");

        customerNameField = new JTextField();
        customerNameField.setPreferredSize(new Dimension(200,30));
        courseNameField = new JTextField();
        courseNameField.setPreferredSize(new Dimension(200,30));
        moneyInsertedField = new JTextField();

        shake = new JCheckBox("Shake");
        shake.addActionListener(this);
        fewa = new JCheckBox("FEWA");
        fewa.addActionListener(this);
        siomaiRice = new JCheckBox("Siomai w/Rice");
        siomaiRice.addActionListener(this);
        noodles = new JCheckBox("Fried Noodles");
        noodles.addActionListener(this);
        hotcake = new JCheckBox("HotCake");
        hotcake.addActionListener(this);
        chickenRice = new JCheckBox("Chicken w/Rice");
        chickenRice.addActionListener(this);
        gulaman = new JCheckBox("Gulaman");
        gulaman.addActionListener(this);
        water = new JCheckBox("Water");
        water.addActionListener(this);

        pwd = new JRadioButton("PWD");
        pwd.addActionListener(this);
        senior = new JRadioButton("Senior");
        senior.addActionListener(this);
        noDisc = new JRadioButton("No Discount");
        noDisc.addActionListener(this);
        discountButtonGroup = new ButtonGroup();
        discountButtonGroup.add(pwd);
        discountButtonGroup.add(senior);
        discountButtonGroup.add(noDisc);

        totalFeeArea = new JTextArea();
        totalFeeArea.setEditable(false);
        changeFeeArea =  new JTextArea();
        changeFeeArea.setEditable(false);
        vatArea = new JTextArea();
        vatArea.setEditable(false);

        compute = new JButton("COMPUTE");
        compute.addActionListener(this);
        cancel = new JButton("CANCEL");
        cancel.addActionListener(this);

        //PANELS
        JPanel titlePanel = new JPanel();
        titlePanel.add(appName);

        JPanel customerInfoPanel = new JPanel();
        customerInfoPanel.setLayout(new GridLayout(2,2,5,5));
        customerInfoPanel.add(customerName);
        customerInfoPanel.add(customerNameField);
        customerInfoPanel.add(courseName);
        customerInfoPanel.add(courseNameField);

        JPanel itemsLbl = new JPanel();
        itemsLbl.add(itemsLabel);
        JPanel itemsPanel = new JPanel();
        itemsPanel.setLayout(new GridLayout(4,2,5,5));
        itemsPanel.add(shake);
        itemsPanel.add(noodles);
        itemsPanel.add(fewa);
        itemsPanel.add(hotcake);
        itemsPanel.add(siomaiRice);
        itemsPanel.add(chickenRice);
        itemsPanel.add(gulaman);
        itemsPanel.add(water);
        JPanel itemsMother = new JPanel();
        itemsMother.setLayout(new BorderLayout());
        itemsMother.add(itemsLbl, BorderLayout.NORTH);
        itemsMother.add(itemsPanel, BorderLayout.CENTER);

        JPanel discountLbl = new JPanel();
        discountLbl.add(discountLabel);
        JPanel discountPanel = new JPanel();
        discountPanel.setLayout(new FlowLayout());
        discountPanel.add(pwd);
        discountPanel.add(senior);
        discountPanel.add(noDisc);
        JPanel discountMother = new JPanel();
        discountMother.add(discountLbl);
        discountMother.add(discountPanel);

        JPanel receiptPanel = new JPanel();
        receiptPanel.setLayout(new GridLayout(4,2,10,10));
        receiptPanel.add(totalLabel);
        receiptPanel.add(totalFeeArea);
        receiptPanel.add(moneyInserted);
        receiptPanel.add(moneyInsertedField);
        receiptPanel.add(changeLabel);
        receiptPanel.add(changeFeeArea);
        receiptPanel.add(vatLabel);
        receiptPanel.add(vatArea);

        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new BoxLayout(centerPanel, BoxLayout.Y_AXIS));
        centerPanel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        centerPanel.add(customerInfoPanel);
        centerPanel.add(Box.createRigidArea(new Dimension(0,10)));
        centerPanel.add(itemsMother);
        centerPanel.add(Box.createRigidArea(new Dimension(0,10)));
        centerPanel.add(discountMother);
        centerPanel.add(Box.createRigidArea(new Dimension(0,10)));
        centerPanel.add(receiptPanel);
        
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());
        buttonPanel.add(compute);
        buttonPanel.add(cancel);

        this.add(titlePanel, BorderLayout.NORTH);
        this.add(centerPanel, BorderLayout.CENTER);
        this.add(buttonPanel, BorderLayout.SOUTH);
        this.pack();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        totalPrice = 0;
        change = 0;
        vat = 0;
        if (shake.isSelected()) totalPrice += 18.25;
        if (fewa.isSelected()) totalPrice += 26.99;
        if (siomaiRice.isSelected()) totalPrice += 45.42;
        if (gulaman.isSelected()) totalPrice += 52.15;
        if (noodles.isSelected()) totalPrice += 60.60;
        if (hotcake.isSelected()) totalPrice += 99.99;
        if (chickenRice.isSelected()) totalPrice += 101.25;
        if (water.isSelected()) totalPrice += 25.35;
        if (pwd.isSelected()) totalPrice *= .75;
        if (senior.isSelected()) totalPrice *= .70;
        if (noDisc.isSelected()) totalPrice *= 1;
        totalFeeArea.setText(String.format("%.2f", totalPrice));

        if (e.getSource() == compute) {
            if (customerNameField.getText().trim().isEmpty()) {
                JOptionPane.showMessageDialog(null, "Error: Please enter your name"); return;
            } if (courseNameField.getText().trim().isEmpty()) {
                JOptionPane.showMessageDialog(null, "Error: Please enter your course"); return;
            }
            try {
                double money = Double.parseDouble(moneyInsertedField.getText());
                change = money - totalPrice - vat;
                vat = totalPrice * .12;

                changeFeeArea.setText(String.format("%.2f", change));
                vatArea.setText(String.format("%.2f", vat));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Error: Please enter a number!"); return;
            }

            
        } if (e.getSource() == cancel) {
            customerNameField.setText("");
            courseNameField.setText("");
            shake.setSelected(false);
            fewa.setSelected(false);
            siomaiRice.setSelected(false);
            noodles.setSelected(false);
            hotcake.setSelected(false);
            chickenRice.setSelected(false);
            gulaman.setSelected(false);
            water.setSelected(false);
            discountButtonGroup.clearSelection();
            totalFeeArea.setText("");
            moneyInsertedField.setText("");
            changeFeeArea.setText("");
            vatArea.setText("");
        }
    }
    
    public static void main(String[] args) {
        new PUPLagoonStore();
    }
}
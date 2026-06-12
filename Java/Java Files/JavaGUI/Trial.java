import javax.swing.*;
import java.awt.event.*;

import java.awt.*;

public class Trial {
  
    JFrame frame;
    JPanel pnl2, pnl3, pnl4, pnl5, pnl6, pnl7;
    
    // Top
    JLabel pnl1;
    ButtonGroup grp1, grp2;
    JRadioButton rb1, rb2, rb3, rb4, rbDiscount;
       
    // Center
    JLabel lbDepart, lbReturn;
    JTextField tfDepart, tfReturn;
    
    String[] tripDomFrom = {"Manila","Cebu"};
    String[] tripDomTo = {"Cebu","Manila"};
    String[] tripIntlFrom  = {"Manila","Hongkong"};  
    String[] tripIntlTo = {"Hongkong","Manila"};        
            
    JComboBox<String> cbFrom, cbTo;
    JLabel lbFrom, lbTo;
    
    String[] arrCheck = {"Add 20kg baggage", "Meal", "Add 32kg baggage", "Choose Seat"};
    JCheckBox[] cbCheck = new JCheckBox[4];
    double[] prices = {200, 300, 500, 1000};
    
    // Bottom
    JLabel lbDiscount, lbTotal;
    JTextField tfDiscount;
    
    JButton btnCompute;
   
    JTextField tfTotal;
    
    double tripPrice = 0;
    
    public Trial() {
        frame = new JFrame("My Project");
        frame.setLayout(new GridLayout(8, 1));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        
        // 1st
        pnl1 = new JLabel("ABC TRAVELS");
        pnl1.setHorizontalAlignment(0);
        
        // 2nd
        pnl2 = createRadioPanel();
        
        //3rd
        pnl3 = createTextFieldPanel();
        
        // 4th
        pnl4 = createComboBox();
        
        pnl5 = createCheckBox();
        
        pnl6 = createDiscount();
        
        pnl7 = createBottom();
        
        frame.add(pnl1);
        frame.add(pnl2);
        frame.add(pnl3);
        frame.add(pnl4);
        frame.add(pnl5);
        frame.add(pnl6);
        frame.add(pnl7);
        
        frame.pack();
        frame.setVisible(true);
    }

    private JPanel createRadioPanel() {
        // 2nd
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2));
        
        grp1 = new ButtonGroup();
        grp2 = new ButtonGroup();
        rb1 = createJRadioButton("One Way", grp1, panel);
        rb2 = createJRadioButton("Round Trip", grp1, panel);       
        rb3 = createJRadioButton("Domestic", grp2, panel);
        rb4 = createJRadioButton("International", grp2, panel);
        
        rb3.addActionListener(changeCountry);
        rb4.addActionListener(changeCountry);
        
        rb2.addActionListener(e -> {
            tfReturn.setEditable(false);
            if(rb2.isSelected()) {
                tfReturn.setEditable(true);
            }
            
        });
        
        return panel;
    }
    
    private JPanel createTextFieldPanel() {
        // 3rd
        JPanel panel = new JPanel();
        lbDepart = new JLabel("Depart: ");
        lbReturn = new JLabel("Return: ");
        
        tfDepart = new JTextField(15);
        tfReturn = new JTextField(15);
        tfDepart.setEditable(false);
        tfReturn.setEditable(false);
        
        panel.add(lbDepart);
        panel.add(tfDepart);
        panel.add(lbReturn);
        panel.add(tfReturn);
        
        return panel;
    }
    
    private JPanel createComboBox() {
        
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2));
        lbFrom = new JLabel("From");
        lbTo = new JLabel("To");
        
        cbFrom = new JComboBox<>();
        cbTo = new JComboBox<>();
        
        
        panel.add(lbFrom);
        panel.add(cbFrom);
        panel.add(lbTo);
        panel.add(cbTo);
        
        return panel;
    }
    
    private JPanel createCheckBox() {
        
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2));
        
        for(int i = 0; i < 4; i++) {
            cbCheck[i] = new JCheckBox(arrCheck[i]);
            panel.add(cbCheck[i]);
        }
        
        return panel;
    }
    
    private JPanel createDiscount() {
        
        JPanel panel = new JPanel();
        
        rbDiscount = new JRadioButton("PWD/Senior Citizen");
        lbDiscount = new JLabel("VOUCHER");
        tfDiscount = new JTextField(15);
        
        tfDiscount.addCaretListener(l -> {
            boolean hasText = !tfDiscount.getText().isEmpty();
            
            if(!hasText) {
                rbDiscount.setEnabled(true);
            }
            
            if(hasText) {
                rbDiscount.setEnabled(false);
            }
        });
        
        panel.add(rbDiscount);
        panel.add(lbDiscount);
        panel.add(tfDiscount);
        
        return panel;
    }
    private JPanel createBottom() {
        
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        
        btnCompute = new JButton("btnCOMPUTE");
        lbTotal = new JLabel("Total Fee:");
        tfTotal = new JTextField(15);
        tfTotal.setEditable(false);
        
        btnCompute.addActionListener(e -> compute());
        
        panel.add(btnCompute, BorderLayout.NORTH);
        JPanel panel1 = new JPanel();
        
        panel1.add(lbTotal);
        panel1.add(tfTotal);
        
        panel.add(panel1);
        
        return panel;
    }
    
    private void compute() {
        double total = 0;
        total += tripPrice;
        
        for(int i = 0; i < 4; i++) {
            if(cbCheck[i].isSelected()) {
                total += prices[i];
            }
        }
        
        
        if(rbDiscount.isSelected()) {
            total *= 0.8;
        } else if (tfDiscount.getText().equals("Chris")) {
            total *= 0;
        }
        
        tfTotal.setText(String.valueOf(total));
    }
    
    private ActionListener changeCountry = e -> {
        if(rb4.isSelected()) {
            tripPrice = 5000;
            cbFrom.setModel(new DefaultComboBoxModel<>(tripIntlFrom));
            cbTo.setModel(new DefaultComboBoxModel<>(tripIntlTo));
        } else if (rb3.isSelected()) {
            tripPrice = 10000;
            cbFrom.setModel(new DefaultComboBoxModel<>(tripDomFrom));
            cbTo.setModel(new DefaultComboBoxModel<>(tripDomTo));
        }
    };
    
    private JRadioButton createJRadioButton(String name, ButtonGroup bg, JPanel pnl) {
        JRadioButton rb = new JRadioButton(name);
        bg.add(rb);
        pnl.add(rb);
        
        return rb;
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new Trial();
        });
    }
    
}





import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Practice2 {
    private JFrame frame;
    
    private JLabel lblHeader, lblDepart, lblReturn, lbFrom, lbTo, lbVoucher, lblTotal;
    
    JPanel pnlRadios, pnlText, pnlCombo, pnlCheck, pnlDiscount, pnlTotal;
    
    JRadioButton rbOneWay, rbRoundTrip, rbDom, rbIntl, rbDiscount;
    ButtonGroup btg1, btg2;
    
    JTextField txtDepart, txtReturn, txtVoucher, txtTotal;
    
    String[] arrDomFrom = {"Manila","Cebu"};
    String[] arrDomTo = {"Cebu","Manila"};
    String[] arrIntlFrom = {"Manila", "Hongkong"};
    String[] arrIntlTo = {"Hongkong", "Manila"};
    
    JComboBox<String> cbFrom, cbTo;
    
    String[] arrAddOns = {"Additional 20kg baggage", "Meal", "Additional 32kg baggage", "Choose Seat"};
    double[] arrAddPrice = {500, 300, 700, 1000};
    JCheckBox[] cbAddOns = new JCheckBox[4];
    
    double tripPrice = 0;
    
    public Practice2() {
        frame = new JFrame();
        frame.setLayout(new GridLayout(8, 1));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        lblHeader = new JLabel("ABC TRAVELS");
        lblHeader.setHorizontalAlignment(0);
        
        pnlRadios = createRadioPanel();
        pnlText = createTextPanel();
        pnlCombo = createComboPanel();
        pnlCheck = createCheckPanel();
        pnlDiscount = createDiscountPanel();
        
        JButton btnCompute = new JButton("btnCOMPUTE");
        btnCompute.addActionListener(e -> compute());
        // TODO
        
        pnlTotal = createTotalPanel();
        
        multiAdd(frame, lblHeader, pnlRadios, pnlText, pnlCombo, pnlCheck, pnlDiscount, btnCompute, pnlTotal);
        
        
        frame.pack();
        frame.setVisible(true);
    }
    
    private JPanel createRadioPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2));
        
        btg1 = new ButtonGroup();
        btg2 = new ButtonGroup();
        
        rbOneWay = createRadioButton("One Way", btg1, panel);
        rbRoundTrip = createRadioButton("RoundTrip", btg1, panel);
        rbDom = createRadioButton("Domestic", btg2, panel);
        rbIntl = createRadioButton("International", btg2, panel);
        
        rbRoundTrip.addActionListener(e -> {
            txtReturn.setEditable(true);
        });
        
        rbDom.addActionListener(countrySwap);
        rbIntl.addActionListener(countrySwap);

        multiAdd(panel, rbOneWay, rbRoundTrip, rbDom, rbIntl);
        
        return panel;
    }
    
    private JPanel createTextPanel() {
        JPanel panel = new JPanel();
        lblDepart = new JLabel("Depart");
        lblReturn = new JLabel("Return");
        
        txtDepart = new JTextField(25);
        txtReturn = new JTextField(25);
        txtDepart.setEditable(false);
        txtReturn.setEditable(false);
        
        multiAdd(panel, lblDepart, txtDepart, lblReturn, txtReturn);
        
        return panel;
    }
    
    private JPanel createComboPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 1));
        
        lbFrom = new JLabel("FROM");
        lbTo = new JLabel("TO");
        cbFrom = new JComboBox<>();
        cbTo = new JComboBox<>();
        
       
        multiAdd(panel, lbFrom, cbFrom, lbTo, cbTo);
        
        return panel;
    }
    
    private JPanel createCheckPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2));
        
        for (int i = 0; i < arrAddOns.length; i++) {
            cbAddOns[i] = new JCheckBox(arrAddOns[i]);
            panel.add(cbAddOns[i]);
        }
        
        return panel;
    }
    
    private JPanel createDiscountPanel() {
        JPanel panel = new JPanel();
        
        rbDiscount = new JRadioButton("PWD/Senior Citizen");
        lbVoucher = new JLabel("VOUCHER");
        txtVoucher = new JTextField(25);
        
        txtVoucher.addCaretListener(l -> {
            boolean hasText = !txtVoucher.getText().isEmpty();
            
            if(!hasText) {
                rbDiscount.setEnabled(true);
            }
            
            if(hasText){
                rbDiscount.setEnabled(false);
            }
        });
        
        multiAdd(panel, rbDiscount, lbVoucher, txtVoucher);
        
        return panel;
    }
    
    private JPanel createTotalPanel() {
        JPanel panel = new JPanel();
        
        lblTotal = new JLabel("Total Fee:");
        txtTotal = new JTextField(25);
        txtTotal.setEditable(false);
        
        multiAdd(panel, lblTotal, txtTotal);
        
        return panel;
    }

    private void compute() {
        double totalPrice = 0;
        totalPrice += tripPrice;
        
        for (int i = 0; i < 4; i++) {
            if (cbAddOns[i].isSelected()) {
                totalPrice += arrAddPrice[i];
            }
        }
        
        if(rbDiscount.isSelected()) {
            totalPrice *= 0.8;
        } else if (txtVoucher.getText().equals("ChrisTV")) {
            totalPrice = 0;
        }
        
        txtTotal.setText(String.valueOf(totalPrice));
    }
    
    private JRadioButton createRadioButton(String name, ButtonGroup btg, JPanel panel) {
        JRadioButton rb = new JRadioButton(name);
        btg.add(rb);
        panel.add(rb);
        
        return rb;
    }

    private void multiAdd(Container con, Component... comp){
        for(Component i: comp) {
            con.add(i);
        }
    }

    ActionListener countrySwap = e -> {
        if(rbDom.isSelected()) {
            tripPrice = 5000;
            cbFrom.setModel(new DefaultComboBoxModel<>(arrDomFrom));
            cbTo.setModel(new DefaultComboBoxModel<>(arrDomTo));
        } else if (rbIntl.isSelected()) {
            tripPrice = 20000;
            cbFrom.setModel(new DefaultComboBoxModel<>(arrIntlFrom));
            cbTo.setModel(new DefaultComboBoxModel<>(arrIntlTo));
        }
    };
    
    public static void main(String args[]) {
        SwingUtilities.invokeLater(() -> {
            Practice2 pract = new Practice2();
        });
    }
}

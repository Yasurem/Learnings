import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SpeedCoding {
    // Core
    private JFrame frame;
    
    // 8 Panels
    private JPanel pnlRadios, pnlTextField, 
                   pnlComboBox, pnlCheck, pnlDiscount, pnlButton, pnlTotal;
    
    // Header panel
    private JLabel lblHeader;
    
    // Radio panel
    private JRadioButton rbOneWay, rbRoundTrip, rbDom, rbIntl;
    private ButtonGroup grpBtn1, grpBtn2;
    
    // TextField Panel
    private JLabel lblDepart, lblReturn;
    private JTextField txtDepart, txtReturn;
    
    // Combo Box Panel
    private JLabel lblFrom, lblTo; 
    private JComboBox<String> combFrom;
    private JComboBox<String> combTo;
    String[] coBDomTo = {"Manila", "Cebu"};
    String[] coBDomFrom = {"Cebu", "Manila"};
    String[] coBIntlTo = {"Manila", "Hongkong"};
    String[] coBIntlFrom = {"Hongkong", "Manila"};
    
    // CheckBox Panel
    private String[] chBAddName = {"Add 20kg", "Meal", "Add 32kg", "Choose Seat"};
    private Checkbox[] chBAdd = new Checkbox[chBAddName.length];
    private String[] chBPrice = {"500", "400", "700", "1000"};
    
    private JRadioButton rbDiscount;
    private JLabel lblDiscount;
    private JTextField txtDiscount;
    
    // button
    private JButton btnCompute;
    
    // txt
    private JLabel lblTotal;
    private JTextField txtTotal;
    
    // Computation
    private double flightPrice = 0;
    private double totalPrice = 0;
    
    public SpeedCoding() {
        // Core
        frame = new JFrame("Hands On");
        frame.setLayout(new GridLayout(8, 1));
        
        // Header
        lblHeader = new JLabel("ABC TRAVELS");
        lblHeader.setHorizontalAlignment(0);
        frame.add(lblHeader);
        
        // Radio panel
        pnlRadios = createRadioPanel();
        pnlTextField = createTextFieldPanel();
        pnlComboBox = createComboBoxPanel();
        pnlCheck = createCheckBoxPanel();
        pnlDiscount = createDiscountPanel();
        
        btnCompute = new JButton("btnCOMPUTE");
        btnCompute.addActionListener(e -> compute());
        
        pnlTotal = createTotalPanel();
        
        multiAdd(frame, pnlRadios, pnlTextField, pnlComboBox, pnlCheck, pnlDiscount, btnCompute, pnlTotal);
        
        frame.add(btnCompute);              
        frame.pack();
        frame.setVisible(true);
        
    }
    
    private JPanel createRadioPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2));
        grpBtn1 = new ButtonGroup();
        grpBtn2 = new ButtonGroup();
        
        rbOneWay = createRadio("One Way", grpBtn1, panel);
        rbRoundTrip = createRadio("Round Trip", grpBtn1, panel);
        rbDom = createRadio("Domestic", grpBtn2, panel);
        rbIntl = createRadio("International", grpBtn2, panel);
        rbDom.addActionListener(countryListener);
        rbIntl.addActionListener(countryListener);
        
        
        return panel;
    }
    
    private JPanel createTextFieldPanel() {
        JPanel panel = new JPanel();
        lblDepart = new JLabel("Depart:");
        lblReturn = new JLabel("Return:");
        
        txtDepart = new JTextField(25);
        txtReturn = new JTextField(25);
        
        txtDepart.setEditable(false);
        txtReturn.setEditable(false);
        
        panel.add(lblDepart);
        panel.add(txtDepart);
        panel.add(lblReturn);
        panel.add(txtReturn);
        
        
        return panel;
    }
    
    private JPanel createComboBoxPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 1));
        combFrom = new JComboBox<>();
        combTo = new JComboBox<>();
        lblFrom = new JLabel("FROM");
        lblTo = new JLabel("TO");
        
        panel.add(lblFrom);
        panel.add(combFrom);
        panel.add(lblTo);
        panel.add(combTo);
        
        return panel;
    }
    
    private JPanel createCheckBoxPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2));
        
        for (int i = 0; i < chBAddName.length; i++) {
            chBAdd[i] = new Checkbox(chBAddName[i]);
            panel.add(chBAdd[i]);
        }        
        
        return panel;
    }
    
    private JPanel createDiscountPanel() {
        JPanel panel = new JPanel();
        rbDiscount = new JRadioButton("PWD / Senior Citizen");
        lblDiscount = new JLabel("VOUCHER");
        txtDiscount = new JTextField(25);
        
        txtDiscount.addCaretListener(l -> {
                boolean hasText = !txtDiscount.getText().isEmpty();
                
                if(!hasText) {rbDiscount.setEnabled(true);}
                
                if(hasText) {
                    rbDiscount.setEnabled(false);
                }
        });
        
        multiAdd(panel, rbDiscount, lblDiscount, txtDiscount);
        
        return panel;
    }
    
    private JPanel createTotalPanel() {
        JPanel panel = new JPanel();
        lblTotal = new JLabel("Total Fee:");
        txtTotal = new JTextField(25);
        txtTotal.setEditable(false);
        
        panel.add(lblTotal);
        panel.add(txtTotal);
        
        return panel;
    }
    
    private void compute() {
        totalPrice = 0;
        totalPrice += flightPrice;
        
        if(rbDiscount.isSelected()) {
            totalPrice *= 0.8;
        } else if(txtDiscount.getText().contains("ChrisTV")) {
            totalPrice = 0;
        }
    
        txtTotal.setText(String.valueOf(totalPrice));
        
    }
    
    private JRadioButton createRadio(String name, ButtonGroup grpBtn, JPanel panel) {
        JRadioButton rb = new JRadioButton(name);
        grpBtn.add(rb);
        panel.add(rb);
        
        return rb;
    }
    
    private ActionListener countryListener = e ->  {
        if (rbDom.isSelected()) {
            flightPrice = 5000;
            combFrom.setModel(new DefaultComboBoxModel<>(coBDomTo));
            combTo.setModel(new DefaultComboBoxModel<>(coBDomFrom));
        } else if (rbIntl.isSelected()) {
            flightPrice = 20000;
            combFrom.setModel(new DefaultComboBoxModel<>(coBIntlTo));
            combTo.setModel(new DefaultComboBoxModel<>(coBIntlFrom));
        }
    };
    
    private void multiAdd(Container cont, Component... comp) {
        for(Component i : comp) {
            cont.add(i);
        }
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SpeedCoding speed = new SpeedCoding();
        });
    }
    
}